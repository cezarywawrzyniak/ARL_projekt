# ARL_projekt
Autonomous Flying Robots project

Projekt sterowania lotem dornów z użyciem markerów aruco.
Dron za pomocą paczki ros2_arcuo wykrywa markery aruco i ustawia ich tfy. Paczka g2r_tf_package zamienia dane z G2RRa na tfa. 
Sterowanie odbywa się za pomocą controler_node'a z paczki tello_controller z użyciem kontorlera PID. 

Do uruchomnienia różnycumh misji w różnych środowiskach służą dopowiednie pliki launch.
real_launch.py posiada parametry z laboratorium.

BRR
![Drone_goes_BRR](https://user-images.githubusercontent.com/80836780/214313128-f7b7615b-b101-47d1-9ecd-0913d7fe85bf.gif)



BRRRR
![Drone_goes_BRRRR](https://user-images.githubusercontent.com/80836780/214314146-0d52bc7b-6ce6-48a4-8c8f-d90281ab3dc3.gif)


BRRRRRR
![Drone_goes_BRRRRRR](https://user-images.githubusercontent.com/80836780/214315608-816f0503-9ed1-4b3c-9d14-6c07749dff2d.gif)



2_BRRRR
![2_Drones_goes_BRR](https://user-images.githubusercontent.com/80836780/214315813-814aed4c-c7f6-4f30-9831-48c51d6bbd7b.gif)



![Map1](https://user-images.githubusercontent.com/80836780/214316930-7ff73b32-a685-42ea-91d5-53411110b861.png)


Parametry:
'follow_markers' lista markerów do odwiedzenia
'drone_topic' topic tello actin
'aruco_topic' topic na którym publikowane są paramtery widzianych aruco
'position_topic' topic zwracający pozycję (G2RR lub optitrack)
'second_mission' zmienna true/false czy dron ma wykonać drugą misję
'dev_in_simulation' zmienna true/false czy odbywa się w symulacji


Uruchomienie następnuje za pomocą launcha <nazwa> z parametrami odpowiadającymi <to do>
