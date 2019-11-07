#pragma once

// NOTE: For the cases where `F::SomeFuncOptions` and `torch::nn::SomeOptions` have the same
// set of parameters, we intentionally make `F::SomeFuncOptions` a subclass of `torch::nn::SomeOptions`
// instead of making them the same class, because we want to prevent the use case of passing
// `torch::nn::SomeOptions` as `F::SomeFuncOptions` into the functionals.
#define TORCH_NN_FUNCTIONAL_USE_MODULE_OPTIONS(MODULE_NAME, FUNCTIONAL_OPTIONS_NAME) \
namespace functional { \
struct FUNCTIONAL_OPTIONS_NAME : public MODULE_NAME##Options { /* NOLINT */ \
 public: \
  using MODULE_NAME##Options::MODULE_NAME##Options; \
}; \
}
