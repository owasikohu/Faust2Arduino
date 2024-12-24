#include <Mozzi.h>
#include "noise.h"

mydsp* dsp;

void setup(){
  dsp = newmydsp();
  initmydsp(dsp, MOZZI_AUDIO_RATE);

	startMozzi();
}

void updateControl(){
}

AudioOutput updateAudio(){
  float sample;
  FAUSTFLOAT* outputs[1] = { &sample };
  computemydsp(dsp, 1, NULL, outputs);

	return MonoOutput::from16Bit(float2int16_t(sample));
}

void loop(){
	audioHook();
}

int16_t float2int16_t(float value) {
  float clampedValue = constrain(value, 0.0f, 1.0f);
  float scaled = (clampedValue * 65535.0f) - 32768.0f;  
  return (int16_t)scaled;
}