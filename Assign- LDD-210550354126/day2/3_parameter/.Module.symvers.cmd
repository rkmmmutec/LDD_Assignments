cmd_/home/pi/device-drivers/assignment/day2/3_parameter/Module.symvers := sed 's/ko$$/o/' /home/pi/device-drivers/assignment/day2/3_parameter/modules.order | scripts/mod/modpost -m -a   -o /home/pi/device-drivers/assignment/day2/3_parameter/Module.symvers -e -i Module.symvers   -T -
