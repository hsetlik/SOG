#pragma once

#include <juce_core/juce_core.h>
#include <juce_audio_processors/juce_audio_processors.h>

// aliases for some of the unwieldy names
typedef juce::AudioProcessorValueTreeState apvts;
typedef juce::NormalisableRange<float> f_range_t;

// https://en.wikipedia.org/wiki/Fast_inverse_square_root
inline float fastInvSqrt(float x) noexcept {
  float x2 = x * 0.5f;
  // it's called we do a little bit hacking
  long i = *(long*)&x;
  i = 0x05F3759DF - (i >> 1);
  x = *(float*)&i;
  x = x * (1.5f - (x2 * x * x));
  return x;
}

inline float fastSqrt(float x) {
  return fastInvSqrt(x) * x;
}

inline float flerp(float a, float b, float t) {
  return a + ((b - a) * t);
}
