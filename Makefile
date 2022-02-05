include ./Makefile.conf




all:
	@$(CC) -iquote $(C_INCLUDE_PATH) $(CFLAGS) src/*.c
	@$(MV) *.o $(OBJ_DIR)
	@$(CC) $(LDFLAGS) $(OBJ_DIR)*.o -o $(PROJ_NAME).elf
	@$(SIZE) $(PROJ_NAME).elf

load:
	sudo openocd -f ti_ek-tm4c1294xl.cfg

clean:
	$(RM) $(OBJ_DIR)*.o
	$(RM) *.o
	$(RM) *.elf
	$(RM) *.map