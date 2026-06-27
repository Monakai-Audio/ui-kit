#include "monakai-ui-kit/Meter.h"

namespace monakai::ui {

Meter::Meter() = default;

void Meter::setLevel(float level)
{
    level_ = juce::jlimit(0.0f, 1.0f, level);
    repaint();
}

void Meter::setForegroundColour(juce::Colour colour)
{
    foregroundColour_ = colour;
    repaint();
}

void Meter::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    auto bounds = getLocalBounds().toFloat().reduced(2.0f);
    const float filledHeight = bounds.getHeight() * level_;
    auto filled = bounds.removeFromBottom(filledHeight);

    g.setColour(foregroundColour_);
    g.fillRect(filled);

    g.setColour(juce::Colours::black);
    g.drawRect(bounds, 1.0f);
}

} // namespace monakai::ui
