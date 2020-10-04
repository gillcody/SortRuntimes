# Define the list of .o files for project
projectOBJECTS = searchAlgorithms.o randomgenlib.o quickSort_str.o quickSort_int.o project3.o
projectINCLUDES = projectHeader.h

# Default Rules for building each .o
%.o: %.c ${projectINCLUDES}
	gcc -g -c $<

# Rule for building the executable
project: ${projectOBJECTS}
	gcc -g -o p3 ${projectOBJECTS}

# Special rule to remove the .o files
clean:
	rm -f ${projectOBJECTS}
