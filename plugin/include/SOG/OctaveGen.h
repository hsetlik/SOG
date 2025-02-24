#pragma once

#include "Common.h"
#include "juce_core/juce_core.h"
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>

/*
 * Polyphonic octave up/down effect based on the Steve Schulteis's
 * implementation of Etienne Thuillier's paper from 2016:
 * https://core.ac.uk/download/pdf/80719011.pdf original code here:
 * https://github.com/schult/terrarium-poly-octave
 * */

// How many bands to split the signal into for processing
#define NUM_SHIFTERS 80

//=============================================================================
class BandShifter {
public:
  BandShifter() = default;

  BandShifter(float center, float bw);
  void update(float sample);
  void prepare(double sampleRate);

  float up1() const { return _up1; }

  float down1() { return _down1.real(); }

  float down2() const { return _down2; }

private:
  float centerFreq;
  float bandwidth;
  float _d0 = 0.0f;
  std::complex<float> _d1;
  std::complex<float> _d2;
  std::complex<float> _c1;
  std::complex<float> _c2;

  std::complex<float> _s1;
  std::complex<float> _s2;

  std::complex<float> _y;
  float _up1 = 0.0f;
  std::complex<float> _down1;
  float _down2 = 0.0f;

  float _down1_sign = 1.0f;
  float _down2_sign = 1.0f;

  void update_filter(float sample);
  void update_up1();

  void update_down1();

  void update_down2();

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BandShifter)
};

//=============================================================================

class OctaveGen {
private:
  juce::OwnedArray<BandShifter> shifters;
  float down1Level;
  float down2Level;
  float upLevel;
  float wetDry;
  double sampleRate;
  bool shiftersReady = false;

public:
  OctaveGen();
  float process(float input);
  void prepare(double sr);
  void updateParams(float d1Gain, float d2Gain, float upGain, float wet) {
    down1Level = d1Gain;
    down2Level = d2Gain;
    upLevel = upGain;
    wetDry = wet;
  }

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OctaveGen)
};
