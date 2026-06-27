#include "monakai-ui-kit/Slider.h"

namespace monakai::ui {

Slider::Slider()
{
    slider_.setSliderStyle(juce::Slider::LinearHorizontal);
    slider_.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider_.setRange(0.0, 1.0, 0.01);
    slider_.addListener(this);
    addAndMakeVisible(slider_);
}

Slider::~Slider()
{
    slider_.removeListener(this);
}

void Slider::setRange(double minimum, double maximum, double interval)
{
    slider_.setRange(minimum, maximum, interval);
}

double Slider::getValue() const
{
    return slider_.getValue();
}

void Slider::setValue(double value, juce::NotificationType notification)
{
    slider_.setValue(value, notification);
}

void Slider::resized()
{
    slider_.setBounds(getLocalBounds());
}

void Slider::sliderValueChanged(juce::Slider* /*slider*/)
{
    if (onValueChanged)
        onValueChanged(slider_.getValue());

    repaint();
}

void Slider::paint(juce::Graphics& g)
{
    const auto bounds = getLocalBounds().toFloat().reduced(2.0f);
    auto trackBounds = bounds.withSizeKeepingCentre(bounds.getWidth(), 4.0f);

    g.setColour(trackColour);
    g.fillRoundedRectangle(trackBounds, 2.0f);

    const float proportion = static_cast<float>(slider_.valueToProportionOfLength(slider_.getValue()));
    auto filledBounds = trackBounds.withWidth(trackBounds.getWidth() * proportion);

    g.setColour(thumbColour);
    g.fillRoundedRectangle(filledBounds, 2.0f);
}

} // namespace monakai::ui
