/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <array>

#include <frc/AddressableLED.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Robot : public frc::TimedRobot {
  static constexpr int kLength = 60;

  // PWM port 9
  // Must be a PWM header, not MXP or DIO
  frc::AddressableLED m_led{9};
  std::array<frc::AddressableLED::LEDData, kLength>
      m_ledBuffer;  // Reuse the buffer
  // Store what the last hue of the first pixel is
  int firstPixelHue = 0;

 public:
  void Rainbow() {
    // For every pixel
// for (int i = 0; i < kLength; i++) {
      // Calculate the hue - hue is easier for rainbows because the color
      // shape is a circle so only one value needs to precess
   //   const auto pixelHue = (firstPixelHue + (i * 180 / kLength)) % 180;
      // Set the value
  //    m_ledBuffer[i].SetHSV(pixelHue, 255, );
  //  }
    // Increase by to make the rainbow "move"
     m_ledBuffer[0].SetHSV(0, 255, 16);
         m_ledBuffer[1].SetHSV(60, 255, 16);
            m_ledBuffer[3].SetHSV(60, 255, 16);
                    m_ledBuffer[2].SetHSV(0, 255, 16);
                            m_ledBuffer[4].SetHSV(0, 255, 16);
    firstPixelHue += 3;
    // Check bounds
    firstPixelHue %= 180;
  }

  void RobotInit() override {
    // Default to a length of 60, start empty output
    // Length is expensive to set, so only set it once, then just update data
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
  }

  void RobotPeriodic() override {
    // Fill the buffer with a rainbow
    Rainbow();
    // Set the LEDs
    m_led.SetData(m_ledBuffer);
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
