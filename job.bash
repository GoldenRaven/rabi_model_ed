#!/bin/bash
photon_num=10
photon_freq=0.1
level_spacing=0.3
coupling=0.2

echo $photon_num  > input.in
echo $photon_freq >> input.in
echo $level_spacing >> input.in
echo $coupling    >> input.in

./rabi_ed.x
