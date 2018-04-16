# embedded_demo_TM4C123_wrapper

This is the wrapping code to my embedded_demo repo to port the code to the TI TM4C123GH6PMI chip (based on ARM Cortex M4).

To build, I used the ti-cgt-arm compiler (version 18.1.1.LTS) in Code Compeser Studio.

This uses TivaWare_C_Series-2.1.4.178 firmware drivers.

Also, to run this, pull down this repo, then in the base project directory,
git clone https://github.com/danbergeland/embedded_demo.git

This project won't build without the above repo pulled in.