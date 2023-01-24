# ARL_projekt
Autonomous Flying Robots project

Projekt sterowania lotem dornów z użyciem markerów aruco.
Dron za pomocą paczki ros2_arcuo wykrywa markery aruco i ustawia ich tfy. Paczka g2r_tf_package zamienia dane z G2RRa na tfa. 
Sterowanie odbywa się za pomocą controler_node'a z paczki tello_controller z użyciem kontorlera PID. 

Do uruchomnienia różnycumh misji w różnych środowiskach służą dopowiednie pliki launch.
real_launch.py posiada parametry z laboratorium.

![Drone_goes_BRR](https://user-images.githubusercontent.com/80836780/214313128-f7b7615b-b101-47d1-9ecd-0913d7fe85bf.gif)


Parametry:
'follow_markers' lista markerów do odwiedzenia
'drone_topic' topic tello actin
'aruco_topic' topic na którym publikowane są paramtery widzianych aruco
'position_topic' topic zwracający pozycję (G2RR lub optitrack)
'second_mission' zmienna true/false czy dron ma wykonać drugą misję
'dev_in_simulation' zmienna true/false czy odbywa się w symulacji


Uruchomienie następnuje za pomocą launcha <nazwa> z parametrami odpowiadającymi <to do>
