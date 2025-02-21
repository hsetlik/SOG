#include "SOG/PluginEditor.h"
#include "SOG/PluginProcessor.h"
#include "juce_gui_basics/juce_gui_basics.h"

namespace audio_plugin {
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p) {
  juce::ignoreUnused(processorRef);
  // add and attach the sliders
  down1Slider.setSliderStyle(juce::Slider::Rotary);
  down1Slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
  down2Slider.setSliderStyle(juce::Slider::Rotary);
  down2Slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
  upSlider.setSliderStyle(juce::Slider::Rotary);
  upSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
  wetSlider.setSliderStyle(juce::Slider::Rotary);
  wetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
  addAndMakeVisible(&down1Slider);
  addAndMakeVisible(&down2Slider);
  addAndMakeVisible(&upSlider);
  addAndMakeVisible(&wetSlider);
  d1Attach = std::make_unique<apvts::SliderAttachment>(
      processorRef.tree, "down1Level", down1Slider);
  d2Attach = std::make_unique<apvts::SliderAttachment>(
      processorRef.tree, "down2Level", down2Slider);
  upAttach = std::make_unique<apvts::SliderAttachment>(processorRef.tree,
                                                       "upLevel", upSlider);
  wetDryAttach = std::make_unique<apvts::SliderAttachment>(processorRef.tree,
                                                           "wetDry", wetSlider);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(400, 600);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {}

void AudioPluginAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  const int dX = (int)(getLocalBounds().toFloat().getWidth() / 10.0f);
  down1Slider.setBounds(0, 0, 5 * dX, 5 * dX);
  down2Slider.setBounds(0, 5 * dX, 5 * dX, 5 * dX);
  upSlider.setBounds(5 * dX, 0, 5 * dX, 5 * dX);
  wetSlider.setBounds(5 * dX, 5 * dX, 5 * dX, 5 * dX);
}
}  // namespace audio_plugin
