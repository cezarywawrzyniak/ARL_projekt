# ARL_projekt
## Autonomous Flying Robots project 
Cezary Wawrzyniak, Jakub Sieklucki, Jakub Marciniak

## Założenia projektu  
Projekt zakładał sterowanie lotem dornów z użyciem markerów aruco. 
Markery byłyby umieszcone na ziemi niestety z powodu kąta widzenia kamery musiało to zostać zmienione.   

## Jak użyć paczki
Należy skożystać z paczki tello_ros (https://github.com/clydemcqueen/tello_ros) i postąpić z jej tutorialem
a następnie sklonować tę paczkę do katalogu src.


## Działanie
Dron za pomocą paczki ros2_arcuo dron wykrywa markery aruco i jest w stanie odczytać ich pozycję.  
Paczka g2r_tf_package zamienia dane z G2RRa na tfa. 
Sterowanie odbywa się za pomocą controler_node'a z paczki tello_controller z użyciem kontorlera PID. 
W niej zapisane jest całe sterowanie dronem

![Dron_goes_BRR](https://user-images.githubusercontent.com/80836780/214312763-63d8d503-a1b0-4505-b3c3-7c2f42312d47.gif)

Do uruchomnienia różnych misji w różnych środowiskach służą dopowiednie pliki launch.
real_launch.py posiada parametry z laboratorium.


Parametry:
'follow_markers' lista markerów do odwiedzenia  
'drone_topic' topic tello actin  
'aruco_topic' topic na którym publikowane są paramtery widzianych aruco  
'position_topic' topic zwracający pozycję (G2RR lub optitrack)  
'second_mission' zmienna true/false czy dron ma wykonać drugą misję  
'dev_in_simulation' zmienna true/false czy odbywa się w symulacji  


Do uruchomienie symulacji należy:  
1. Uruchomić skrytpy start_tello w katalaogu vm_scripts
2. Włączyć G2RR poleceniem ```ros2 run G2RR g2rr tello_1 ```
3. Uruchomić launcha wchodząc w folder ```tello_controller/launch``` a następnie ```ros2 launch <nazwa launcha>```

Uruchomienie z prawdziwym dronem jest bardzo podobne:
1. Uruchomić teleopa
2. Połączyć się z optitrackiem
3. Uruchomić launcha wchodząc w folder ```tello_controller/launch``` a następnie ```ros2 launch <nazwa launcha>```




## Użyte paczki
Do sterowania dronem:
https://github.com/clydemcqueen/tello_ros
Już w repo
https://github.com/JMU-ROBOTICS-VIVA/ros2_aruco
