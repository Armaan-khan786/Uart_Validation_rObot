*** Settings ***
Library    uart_library.py

*** Test Cases ***
Strict UART Firmware Validation
    Open Ports    COM7    115200
    Send Data     HELLO
    ${response}=  Read Data
    Should Not Be Empty    ${response}
    Close Ports