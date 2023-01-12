# On-demand-traffic-Application-Udacity-FWD

This is an on-demand smart traffic light system for the embedded systems professional track by Egypt FWD and Udacity. The main objective is to decrease waiting time for pedestrians as they have higher priority.  The system has 2 modes: 
* Normal mode
* Pedestrian mode.
In normal mode, the cars traffic light operates normally (Red -> Yellow -> Green and repeat).  
But for pedestrian mode, which means a pedestrian pressed the button while the normal mode is on and for this, we have multiple scenarios:
* Pressed while red for pedestrians -> Goes to yellow immediately for 5 seconds then green for pedestrians.
* Pressed while yellow and in its way to red for pedestrians -> Completes the yellow blinking state but then goes to green for pedestrians.
* Pressed while yellow and in its way to green for pedestrians -> Completes its normal path, blinking yellow then green. 
* Pressed while green for pedestrians -> No effect.


You may check the recording for testing the application:  
https://nileuniversity-my.sharepoint.com/:v:/g/personal/mamostafa_nu_edu_eg/EUmxBzr0ThpMkBM9sn7TTzsBpVeDA_SGMLlk-X8_MAWu6Q?e=ghdJTa
