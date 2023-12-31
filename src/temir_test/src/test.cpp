// //#include <moveit/move_group_interface/move_group.h>
// #include <moveit/planning_scene_interface/planning_scene_interface.h>
// #include <moveit/move_group_interface/move_group_interface.h>
// #include <moveit_msgs/DisplayRobotState.h>
// #include <moveit_msgs/DisplayTrajectory.h>
// #include <moveit_msgs/AttachedCollisionObject.h>
// #include <moveit_msgs/CollisionObject.h>
// //#include <moveit_visual_tools/moveit_visual_tools.h>
// // Main moveit libraries are included
// int main(int argc, char **argv){
//     ros::init(argc, argv, "move_group_interface_tutorial");
//     ros::NodeHandle node_handle;
//     ros::AsyncSpinner spinner(0);

//     spinner.start(); // For moveit implementation we need AsyncSpinner, we cant use
//     ros::spinOnce();
//     static const std::string PLANNING_GROUP = "full_robot"; /* Now we specify with
//     what group we want work,
//     here group1 is the name of my group controller*/

//     moveit::planning_interface::MoveGroupInterface
//     move_group(PLANNING_GROUP); // loading move_group
//     const robot_state::JointModelGroup *joint_model_group =
//     move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

//     //For joint control
//     geometry_msgs::PoseStamped current_pose;
//     geometry_msgs::PoseStamped target_pose; // Pose in ROS is implemented using
//     // geometry_msgs::PoseStamped, google what is the type of this msg

//     current_pose = move_group.getCurrentPose(); /* Retrieving the information about
//     the
//     current position and orientation of the end effector*/

//     target_pose = current_pose;
//     target_pose.pose.position.x = target_pose.pose.position.x - 0.8; /* Basically our
//     target pose is the same as current,
//     except that we want to move it a little bit along x-axis*/

//     ros::Rate loop_rate(50); //Frequency

//     while (ros::ok())
//     {
//         move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
//         move_group.move(); // Move the robot
//         current_pose = move_group.getCurrentPose();

//         if (abs(current_pose.pose.position.x - target_pose.pose.position.x) < 0.01){
//             break; // Basically, check if we reached the desired position
//         }
//         loop_rate.sleep();
//     }

//     target_pose = current_pose;
//     target_pose.pose.position.y = target_pose.pose.position.y + 0.8; /* Basically our
//     target pose is the same as current,
//     except that we want to move it a little bit along x-axis*///

//     while (ros::ok())
//     {
//         move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
//         move_group.move(); // Move the robot
//         current_pose = move_group.getCurrentPose();

//         if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
//             break; // Basically, check if we reached the desired position
//         }
//         loop_rate.sleep();
//     }

//     target_pose = current_pose;
//     target_pose.pose.position.x = target_pose.pose.position.x + 0.8; /* Basically our
//     target pose is the same as current,
//     except that we want to move it a little bit along x-axis*///

//     while (ros::ok())
//     {
//         move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
//         move_group.move(); // Move the robot
//         current_pose = move_group.getCurrentPose();

//         if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
//             break; // Basically, check if we reached the desired position
//         }
//         loop_rate.sleep();
//     }

//     target_pose = current_pose;
//     target_pose.pose.position.y = target_pose.pose.position.y - 0.8; /* Basically our
//     target pose is the same as current,
//     except that we want to move it a little bit along x-axis*///

//     while (ros::ok())
//     {
//         move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
//         move_group.move(); // Move the robot
//         current_pose = move_group.getCurrentPose();

//         if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
//             break; // Basically, check if we reached the desired position
//         }
//         loop_rate.sleep();
//     }
    
//     ROS_INFO("Done");
//     ros::shutdown();
//     return 0;
// }


//#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
//#include <moveit_visual_tools/moveit_visual_tools.h>
// Main moveit libraries are included
int main(int argc, char **argv){
    int i;
    int radius=0.4;
    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(0);

    spinner.start(); // For moveit implementation we need AsyncSpinner, we cant use
    ros::spinOnce();
    static const std::string PLANNING_GROUP = "full_robot"; /* Now we specify with
    what group we want work,
    here group1 is the name of my group controller*/

    moveit::planning_interface::MoveGroupInterface
    move_group(PLANNING_GROUP); // loading move_group
    const robot_state::JointModelGroup *joint_model_group =
    move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    //For joint control
    geometry_msgs::PoseStamped current_pose;
    geometry_msgs::PoseStamped target_pose; // Pose in ROS is implemented using
    // geometry_msgs::PoseStamped, google what is the type of this msg

    current_pose = move_group.getCurrentPose(); /* Retrieving the information about
    the
    current position and orientation of the end effector*/

    // target_pose = current_pose;
    // target_pose.pose.position.x = target_pose.pose.position.x - 0.1;
    // target_pose.pose.position.y = target_pose.pose.position.y - 0.1;
    // target pose is the same as current,
    // except that we want to move it a little bit along x-axis*/

    ros::Rate loop_rate(50); //Frequency

    while (ros::ok())
    {
        i=0;
        target_pose = current_pose;
        target_pose.pose.position.x = target_pose.pose.position.x - sin(2 * radius * 3.14159265359 / 360);
        target_pose.pose.position.y = target_pose.pose.position.y - cos(2 * radius * 3.14159265359 / 360);
        while(i<30){
            i++;

            move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
            move_group.move(); // Move the robot
            current_pose = move_group.getCurrentPose();

            if (abs(current_pose.pose.position.x - target_pose.pose.position.x) < 0.01){
                break; // Basically, check if we reached the desired position
            }
            // if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
            //     break; // Basically, check if we reached the desired position
            // }
            loop_rate.sleep();
        }
    }

    // target_pose = current_pose;
    // target_pose.pose.position.y = target_pose.pose.position.y + 0.8; /* Basically our
    // target pose is the same as current,
    // except that we want to move it a little bit along x-axis*///

    // while (ros::ok())
    // {
    //     move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
    //     move_group.move(); // Move the robot
    //     current_pose = move_group.getCurrentPose();

    //     if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
    //         break; // Basically, check if we reached the desired position
    //     }
    //     loop_rate.sleep();
    // }

    // target_pose = current_pose;
    // target_pose.pose.position.x = target_pose.pose.position.x + 0.8; /* Basically our
    // target pose is the same as current,
    // except that we want to move it a little bit along x-axis*///

    // while (ros::ok())
    // {
    //     move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
    //     move_group.move(); // Move the robot
    //     current_pose = move_group.getCurrentPose();

    //     if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
    //         break; // Basically, check if we reached the desired position
    //     }
    //     loop_rate.sleep();
    // }

    // target_pose = current_pose;
    // target_pose.pose.position.y = target_pose.pose.position.y - 0.8; /* Basically our
    // target pose is the same as current,
    // except that we want to move it a little bit along x-axis*///

    // while (ros::ok())
    // {
    //     move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
    //     move_group.move(); // Move the robot
    //     current_pose = move_group.getCurrentPose();

    //     if (abs(current_pose.pose.position.y - target_pose.pose.position.y) < 0.01){
    //         break; // Basically, check if we reached the desired position
    //     }
    //     loop_rate.sleep();
    // }
    
    ROS_INFO("Done");
    ros::shutdown();
    return 0;
}