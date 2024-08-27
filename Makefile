FOLDERS = boilerplate \
		  encapsulation/ex00 \
		  encapsulation/ex01

	@for folder in $(FOLDERS); do \
		make -C ./$$folder; \
	done

run:
	@for folder in $(FOLDERS); do \
		make -C ./$$folder run; \
	done

clean:
	@for folder in $(FOLDERS); do \
		make -C ./$$folder clean; \
	done

fclean:
	@for folder in $(FOLDERS); do \
		make -C ./$$folder fclean; \
	done

re:
	@for folder in $(FOLDERS); do \
		make -C ./$$folder re; \
	done
