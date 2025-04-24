#pragma XOD require "https://github.com/BreadBoardMates/Arduino-Mates-Controller"

#include <MatesController.h>

node {
    meta {
        using Type = MatesController*;
    }

    auto uart = getValue<input_UART>(ctx);
    static_assert(isValidDigitalPort(constant_input_RESET), "must be a valid digital port");


    void evaluate(Context ctx) {

        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        MatesController mate = MatesController(*(uart->toStream()), constant_input_RESET);

        emitValue<output_MATE>(ctx, &mate);
    }
}
