OBJS = Takeanapple.o
TARGET = Takeanapple
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
clean:
	$(RM) $(OBJS) $(TARGET)

