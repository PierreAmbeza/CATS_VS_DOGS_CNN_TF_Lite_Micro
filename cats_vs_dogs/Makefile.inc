
$(warning mnist demo Makefile has been included)

CATS_VS_DOGS_DEMO_SRCS := \
tensorflow/lite/micro/examples/cats_vs_dogs/main.cc \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_model.cc

CATS_VS_DOGS_DEMO_HDRS := \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_model.h \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_test_data.h

CATS_VS_DOGS_DEMO_TEST_SRCS := \
tensorflow/lite/micro/examples/cats_vs_dogs/cats_vs_dogs_demo_test.cc \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_model.cc

CATS_VS_DOGS_DEMO_TEST_HDRS := \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_model.h \
tensorflow/lite/micro/examples/cats_vs_dogs/model/cats_vs_dogs_test_data.h

# Find any platform-specific rules for this example.
include $(wildcard tensorflow/lite/micro/examples/cats_vs_dogs/*/Makefile.inc)

# Tests the character classifier model with a seven.
$(eval $(call microlite_test,micro_cats_vs_dogs_test,\
$(CATS_VS_DOGS_DEMO_TEST_SRCS),$(CATS_VS_DOGS_DEMO_TEST_HDRS)))

# Builds an MNIST character classifier demo binary.
$(eval $(call microlite_test,micro_cats_vs_dogs,\
$(CATS_VS_DOGS_DEMO_SRCS),$(CATS_VS_DOGS_DEMO_HDRS)))

