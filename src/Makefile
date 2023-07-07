all:
print_module:
	gcc -Werror -Wall -Wextra -fsanitize=address -fsanitize=leak print_module.c main_module_entry_point.c -DPRINT_LOG -o ../build/Quest_1
documentation_module:
	gcc -Werror -Wall -Wextra -fsanitize=address -fsanitize=leak documentation_module.c main_module_entry_point.c -DDOCUMENTS -o ../build/Quest_2
bst_create_test:
	gcc -Werror -Wall -Wextra -fsanitize=address -fsanitize=leak bst.c bst_create_test.c -o ../build/Quest_3
bst_insert_test:
	gcc -Werror -Wall -Wextra -fsanitize=address -fsanitize=leak bst.c bst_insert_test.c -o ../build/Quest_4
clean:
	rm ../build/Quest_*
rebuild: clean all