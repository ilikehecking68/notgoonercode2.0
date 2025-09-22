#pragma once

#include "lemlib/config.hpp"
#include "hot-cold-asset/asset.hpp"
#include "pros/adi.hpp"

namespace lemlib {
struct FollowParams {
        bool reversed = false;
        Number lateralSlew = lateral_slew;
};

struct FollowSettings {
        Length trackWidth = track_width;
        std::function<units::Pose()> poseGetter = pose_getter;
        lemlib::MotorGroup& leftMotors = left_motors;
        lemlib::MotorGroup& rightMotors = right_motors;
};

struct Path_Motor {
    uint8_t index;
    pros::Motor& corrosponding;
};

struct Path_3_Wire_Digital_Out {
    uint8_t index;
    pros::ADIDigitalOut& corrosponding;
};

struct Path_Function {
    size_t index;
    std::function<void()>& func;
    std::function<void()>& reset_func;
};

void follow(const asset& asset, Length lookaheadDistance, Time timeout, FollowParams params, FollowSettings settings, const std::vector<Path_Motor> motors, const std::vector<Path_3_Wire_Digital_Out> three_wires, const std::vector<Path_Function> funcs);
} // namespace lemlib