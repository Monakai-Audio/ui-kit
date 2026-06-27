#include "monakai-ui-kit/Knob.h"

namespace monakai::ui {

Knob::Knob()
{
    slider_.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider_.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider_.setRange(0.0, 1.0, 0.01);
    slider_.addListener(this);
    addAndMakeVisible(slider_);
}

Knob::~Knob()
{
    slider_.removeListener(this);
}

void Knob::setRange(double minimum, double maximum, double interval)
{
    slider_.setRange(minimum, maximum, interval);
}

double Knob::getValue() const
{
    return slider_.getValue();
}

void Knob::setValue(double value, juce::NotificationType notification)
{
    slider_.setValue(value, notification);
}

void Knob::resized()
{
    slider_.setBounds(getLocalBounds());
}

void Knob::sliderValueChanged(juce::Slider* /*slider*/)
{
    if (onValueChanged)
        onValueChanged(slider_.getValue());

    repaint();
}

void Knob::paint(juce::Graphics& g)
{
    const auto bounds = getLocalBounds().toFloat().reduced(4.0f);
    const auto radius = juce::jmin(bounds.getWidth(), bounds.getHeight()) * 0.5f;
    const auto centre = bounds.getCentre();

    const float startAngle = juce::MathConstants<float>::pi * 1.25f;
    const float endAngle   = juce::MathConstants<float>::pi * 2.75f;
    const float proportion = static_cast<float>(slider_.valueToProportionOfLength(slider_.getValue()));

    juce::Path backgroundArc;
    backgroundArc.addCentredArc(centre.x, centre.y, radius, radius,
                                0.0f, startAngle, endAngle, true);
    g.setColour(arcColour);
    g.strokePath(backgroundArc, juce::PathStrokeType(4.0f));

    juce::Path valueArc;
    valueArc.addCentredArc(centre.x, centre.y, radius, radius,
                           0.0f, startAngle,
                           startAngle + proportion * (endAngle - startAngle), true);
    g.setColour(thumbColour);
    g.strokePath(valueArc, juce::PathStrokeType(4.0f));
}

} // namespace monakai::ui
