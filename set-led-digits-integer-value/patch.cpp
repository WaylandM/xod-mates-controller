
node {
  
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        
        auto mates = getValue<input_DEV>(ctx);
        uint8_t idx = getValue<input_Index>(ctx);
        int16_t val = round(getValue<input_Value>(ctx));

        if (!mates->setLedDigitsValue(idx, val)) {
            raiseError(ctx);
            return;
        }

        emitValue<output_OK>(ctx, 1);
    }
}
