#pragma once

#include "PluginProcessor.h"

namespace audio_plugin {

class AudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
  ~AudioPluginAudioProcessorEditor() override;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // sliders and they attachments
  juce::Slider down1Slider;
  std::unique_ptr<apvts::SliderAttachment> d1Attach;
  juce::Slider down2Slider;
  std::unique_ptr<apvts::SliderAttachment> d2Attach;
  juce::Slider upSlider;
  std::unique_ptr<apvts::SliderAttachment> upAttach;
  juce::Slider wetSlider;
  std::unique_ptr<apvts::SliderAttachment> wetDryAttach;
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
}  // namespace audio_plugin
