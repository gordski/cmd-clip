APP = cmd-clip
OBJS = clip.o searcher.o main.o

all: $(APP)

%.o: %.cpp
	@echo "C++ $<"
	@g++ --std=c++11 -g $^ -c -o $@

$(APP): $(OBJS)
	@echo "LD $(APP)"
	@g++ $(LDFLAGS) -g $^ -o $@

clean:
	@for obj in "$(OBJS) $(APP)"; do\
		echo "RM $${obj}"; \
		rm $${obj} 2>/dev/null; \
	done;
