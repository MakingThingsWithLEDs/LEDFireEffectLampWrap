/*
 * Torch: https://github.com/evilgeniuslabs/torch
 * Copyright (C) 2015 Jason Coon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


uint16_t analyzerPixels() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);

  for (uint8_t bandIndex = 0; bandIndex < bandCount; bandIndex++) {
    int levelLeft = levelsLeft[bandIndex];
    int levelRight = levelsRight[bandIndex];

    if (drawPeaks) {
      levelLeft = peaksLeft[bandIndex];
      levelRight = peaksRight[bandIndex];
    }

    CRGB colorLeft = ColorFromPalette(palette, levelLeft / levelsPerHue);
    CRGB colorRight = ColorFromPalette(palette, levelRight / levelsPerHue);

    uint8_t x = bandIndex + bandOffset;
    if (x >= MATRIX_WIDTH)
      x -= MATRIX_WIDTH;

    leds[XY(x, (MATRIX_HEIGHT - 1) - levelLeft / levelsPerVerticalPixel)] = colorLeft;
    leds[XY(x + bandCount, (MATRIX_HEIGHT - 1) - levelLeft / levelsPerVerticalPixel)] = colorRight;
  }

  return 0;
}


uint16_t audioFire() {
  moveUp();

  for (uint8_t bandIndex = 0; bandIndex < bandCount; bandIndex++) {
    int levelLeft = levelsLeft[bandIndex];
    int levelRight = levelsRight[bandIndex];

    if (drawPeaks) {
      levelLeft = peaksLeft[bandIndex];
      levelRight = peaksRight[bandIndex];
    }

    if (levelLeft <= 8) levelLeft = 0;
    if (levelRight <= 8) levelRight = 0;

    CRGB colorLeft = ColorFromPalette(HeatColors_p, levelLeft / 5);
    CRGB colorRight = ColorFromPalette(HeatColors_p, levelRight / 5);

    uint8_t x = bandIndex + bandOffset;
    if (x >= MATRIX_WIDTH)
      x -= MATRIX_WIDTH;

    leds[XY(x, MATRIX_HEIGHT - 1)] = colorLeft;
    leds[XY(x + bandCount, MATRIX_HEIGHT - 1)] = colorRight;
  }

  return 0;
}
//.....................................

uint16_t audioFire2() {
  moveUp();

  for (uint8_t bandIndex = 0; bandIndex < bandCount; bandIndex++) {
    int levelLeft = levelsLeft[bandIndex];
    int levelRight = levelsRight[bandIndex];

    if (drawPeaks) {
      levelLeft = peaksLeft[bandIndex];
      levelRight = peaksRight[bandIndex];
    }

    if (levelLeft <= 8) levelLeft = 0;
    if (levelRight <= 8) levelRight = 0;

    CRGB colorLeft = ColorFromPalette(OceanColors_p, levelLeft / 5);
    CRGB colorRight = ColorFromPalette(OceanColors_p, levelRight / 5);

    uint8_t x = bandIndex + bandOffset;
    if (x >= MATRIX_WIDTH)
      x -= MATRIX_WIDTH;

    leds[XY(x, MATRIX_HEIGHT - 1)] = colorLeft;
    leds[XY(x + bandCount, MATRIX_HEIGHT - 1)] = colorRight;
  }

  return 0;
}
//.........................................


uint16_t blackAndBlueAudioNoise() {
  SetupBlackAndBlueStripedPalette();
  static int lastPeak0 = 0;

  noisespeedx = 0;

  if (peaksLeft[0] >= lastPeak0) {
    noisespeedx = peaksLeft[0] / 57;
  }

  lastPeak0 = peaksLeft[0];

  noisespeedy = 0;
  noisespeedz = 0;
  noisescale = 45;
  colorLoop = 0;
  return drawNoise(blackAndBlueStripedPalette);
}
