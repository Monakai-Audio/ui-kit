# Monakai Audio UI Kit

![CI](https://github.com/monakai-audio/ui-kit/actions/workflows/ci.yml/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)

Reusable, style-agnostic JUCE UI components: knobs, sliders, meters, and
waveform displays. This library intentionally contains no Monakai branding,
logos, colors, or proprietary DSP so it can be reused across projects.

> **Proprietary notice:** DSP algorithms and premium content remain proprietary
> to Monakai Audio. This repository only contains generic UI components.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Repository structure](#repository-structure)
- [Contributing](#contributing)
- [Security](#security)
- [License](#license)

## Features

- `Knob` — rotary control with customizable arc and thumb colors
- `Slider` — linear slider wrapper with value-changed callback
- `Meter` — simple vertical level meter
- `WaveformDisplay` — component that draws a mono sample buffer

## Requirements

- C++17 compiler
- CMake 3.22 or newer
- JUCE 7 or newer (fetched automatically by CMake)

## Installation

```bash
git clone https://github.com/monakai-audio/ui-kit.git
cd ui-kit
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 4
```

## Usage

```cpp
#include <monakai-ui-kit/Knob.h>
#include <monakai-ui-kit/Meter.h>

monakai::ui::Knob frequencyKnob;
frequencyKnob.setRange(20.0, 20000.0, 1.0);
frequencyKnob.onValueChanged = [](double value) {
    // Update parameter
};

monakai::ui::Meter outputMeter;
outputMeter.setLevel(0.5f);
```

## Repository structure

```
ui-kit/
├── include/monakai-ui-kit/ # Public component headers
├── src/                    # Component implementations
├── .github/workflows/      # CI verification
├── CMakeLists.txt
├── LICENSE
├── README.md
├── CODE_OF_CONDUCT.md
└── SECURITY.md
```

## Contributing

See [Contributing Guide](../docs/docs/contributing.md) and
[Code of Conduct](./CODE_OF_CONDUCT.md).

## Security

See [SECURITY.md](./SECURITY.md).

## License

This repository is licensed under the [MIT License](./LICENSE).
