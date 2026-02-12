*** Settings ***
Library    Process

*** Test Cases ***
UART Firmware Validation Test
    ${result}=    Run Process    python    uart_test.py    shell=True    stdout=PIPE    stderr=PIPE
    Log    ${result.stdout}
    Should Be Equal As Integers    ${result.rc}    0