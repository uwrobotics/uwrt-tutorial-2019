# uwrt-tutorial-2019

## To compile code:
- From root folder:
```
$ catkin_make
```

## To run basic pubsub
- From root folder:
```
$ roscore
```
In a new terminal tab/window, from same folder:
```
$ source devel/setup.bash
$ rosrun uwrt_tut pub_node
```
In a new terminal tab/window, from same folder:
```
$ source devel/setup.bash
$ rosrun uwrt_tut sub_node
```
sub_node should print the messages received from pub_node.

## To run turtle_control
- From root folder:
```
$ roscore

```
In a new terminal tab/window, from same folder:
```
$ rosrun turtlesim turtlesim_node
```
The turtlebot simulator should appear.
In a new terminal tab/window, from same folder:
```
$ source devel/setup.bash
$ rosrun turtle_control turtle_contronode
```
In a new terminal tab/window:
```
$ rostopic pub /goal geometry_msgs/Point "x: 8.0 y: 7.0 z: 0.0"
```
The turtle will move to the coordinate you specify. Try out other coordinates.






