
node {

    void evaluate(Context ctx) {

        // The node responds only if there is an input pulse
        if (!isInputDirty<input_INIT>(ctx))
            return;

        auto mates = getValue<input_DEV>(ctx);

        // Attempt to initialize; if attempt fails emit error
        if (!mates->begin()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_OK>(ctx, 1);


    }
}
