FOLDERS = boilerplate

run:
	@for folder in $(FOLDERS); do \
		make -C ./$$folder; \
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
