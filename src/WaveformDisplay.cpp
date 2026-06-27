#include "monakai-ui-kit/WaveformDisplay.h"

namespace monakai::ui {

WaveformDisplay::WaveformDisplay() = default;

void WaveformDisplay::setSamples(const float* samples, size_t numSamples)
{
    samples_.assign(samples, samples + numSamples);
    repaint();
}

void WaveformDisplay::setWaveformColour(juce::Colour colour)
{
    waveformColour_ = colour;
    repaint();
}

void WaveformDisplay::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);

    if (samples_.empty())
        return;

    auto bounds = getLocalBounds().toFloat().reduced(2.0f);
    const float midY = bounds.getCentreY();
    const float scaleY = bounds.getHeight() * 0.5f;
    const float stepX = bounds.getWidth() / static_cast<float>(samples_.size());

    juce::Path path;
    path.startNewSubPath(bounds.getX(), midY);

    for (size_t i = 0; i < samples_.size(); ++i)
    {
        const float x = bounds.getX() + static_cast<float>(i) * stepX;
        const float y = midY - samples_[i] * scaleY;
        path.lineTo(x, y);
    }

    g.setColour(waveformColour_);
    g.strokePath(path, juce::PathStrokeType(1.0f));
}

} // namespace monakai::ui
