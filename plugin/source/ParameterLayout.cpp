#include "SOG/ParameterLayout.h"

namespace SOG {
apvts::ParameterLayout createPluginLayout() {
  apvts::ParameterLayout layout;
  f_range_t fxLevelRange(0.0f, 1.0f);
  const float minus12 = juce::Decibels::decibelsToGain<float>(-12.0f);
  fxLevelRange.setSkewForCentre(minus12);
  f_range_t wetDryRange(0.0f, 1.0f);
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      "down1Level", "Down 1 Level", fxLevelRange, minus12));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      "down2Level", "Down 2 Level", fxLevelRange, 0.0f));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      "upLevel", "Up 1 Level", fxLevelRange, minus12));
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      "wetDry", "Wet/Dry mix", wetDryRange, 0.75f));
  return layout;
}
}  // namespace SOG
