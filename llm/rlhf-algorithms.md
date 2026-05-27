# RLHF Algorithm Notes

Concise, public-safe notes for common post-training algorithms.

## PPO

Proximal Policy Optimization is a policy-gradient method that limits how much the updated policy can move away from the old policy in one step.

In RLHF-style training, PPO usually uses:

- A policy model that generates responses.
- A reward model or rule-based reward that scores responses.
- A value model or critic that estimates expected future reward.
- A KL penalty to keep the policy close to a reference model.

The clipped objective is commonly written as:

$$
L^{CLIP}(\theta)=\mathbb{E}\left[\min(r_t(\theta)A_t,\text{clip}(r_t(\theta),1-\epsilon,1+\epsilon)A_t)\right]
$$

where:

- $r_t(\theta)$ is the probability ratio between the new policy and old policy.
- $A_t$ is the advantage estimate.
- $\epsilon$ controls the update trust region.

Main trade-off: PPO is stable and widely used, but it is memory-heavy because it often needs a critic/value model in addition to the policy and reference model.

## GRPO

Group Relative Policy Optimization removes the separate critic and estimates advantage by comparing multiple sampled answers for the same prompt.

For one prompt, sample a group of responses and score each response. A simple normalized advantage is:

$$
A_i=\frac{r_i-\mu}{\sigma}
$$

where:

- $r_i$ is the reward for response $i$.
- $\mu$ is the group mean reward.
- $\sigma$ is the group reward standard deviation.

Main idea: responses are judged relative to other responses from the same prompt. This can reduce memory use compared with PPO because no separate critic is required.

Main trade-off: GRPO works best when group sampling is meaningful and affordable. If each rollout changes the environment state, grouping many samples from the same state may become expensive or ill-defined.

## DPO

Direct Preference Optimization trains a policy directly from preference pairs without running an online RL loop.

The data format is usually:

- Prompt $x$
- Preferred response $y_w$
- Rejected response $y_l$

DPO increases the relative likelihood of the preferred response while using a reference model to control drift. A common form is:

$$
L_{DPO}=-\log\sigma\left(\beta\left[
\log\frac{\pi_\theta(y_w|x)}{\pi_{ref}(y_w|x)}
-
\log\frac{\pi_\theta(y_l|x)}{\pi_{ref}(y_l|x)}
\right]\right)
$$

Main idea: convert preference learning into a supervised-style objective.

Main trade-off: DPO is simpler than PPO and does not need a reward model at training time, but it depends heavily on the quality and coverage of preference data.

## Reinforce++

Reinforce++ is a family of critic-free policy-gradient variants based on sequence-level or token-level returns.

Common ingredients:

- Use sampled rollouts from the current policy.
- Assign rewards to full responses or episodes.
- Apply KL penalties to keep the policy close to a reference model.
- Normalize or whiten rewards/advantages within a batch to reduce variance.

For sparse rewards, the return can be assigned at the end of a sequence and propagated backward with a discount factor:

$$
G_t = r_t + \gamma G_{t+1}
$$

Main idea: avoid maintaining a critic while still improving the policy from sampled rewards.

Main trade-off: it is simpler and lighter than PPO, but variance control becomes important. Batch-level normalization, reward shaping, and KL tuning matter a lot.

## Quick Comparison

| Algorithm | Needs Critic | Needs Preference Pairs | Online Rollout | Common Strength |
| --- | --- | --- | --- | --- |
| PPO | Usually yes | No | Yes | Stable RL updates |
| GRPO | No | No | Yes | Critic-free group comparison |
| DPO | No | Yes | No | Simple preference tuning |
| Reinforce++ | No | No | Yes | Lightweight policy-gradient training |

## Interview Checklist

- Explain what signal defines "better": reward model, rule reward, preference pair, or group-relative score.
- Explain how the method prevents policy drift: clipping, KL penalty, or reference-model ratio.
- Explain the memory cost: critic-free methods are usually lighter than PPO.
- Explain the failure mode: noisy rewards, poor preference data, weak exploration, or unstable KL.
