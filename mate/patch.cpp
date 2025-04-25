#pragma XOD require "https://github.com/BreadBoardMates/Arduino-Mates-Controller"

#include <MatesController.h>

node {
    meta {
        using Type = MatesController*;
    }

    static_assert(isValidDigitalPort(constant_input_RESET), "must be a valid digital port");

    uint8_t mem[sizeof(MatesController)];
    // Create an object of class MatesController
    //MatesController mates = MatesController();



    void evaluate(Context ctx) {

        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto uart = getValue<input_UART>(ctx);
        //MatesController mates = MatesController(*(uart->toStream()), constant_input_RESET);
        //MatesController mates = MatesController(*(uart->toStream()));
        //MatesController mates = MatesController(Serial1);

        Type mates = new (mem) MatesController(*(uart->toStream()), constant_input_RESET);

        emitValue<output_DEV>(ctx, mates);
    }
}
