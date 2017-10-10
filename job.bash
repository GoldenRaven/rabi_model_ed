#!/bin/bash
make
photon_num=1000
photon_freq=0.5
level_spacing=1
coupling=0.5

echo $photon_num  > input.in
echo $photon_freq >> input.in
echo $level_spacing >> input.in
echo $coupling    >> input.in

./rabi_ed.x > out
