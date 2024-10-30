#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius > 200) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

void testFailure() {
    alertFailureCount = 0;

    alertInCelcius(400.5);
    assert(alertFailureCount == 1);

    alertInCelcius(303.6);
    assert(alertFailureCount == 1);
}

int main() {
    testFailure();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
