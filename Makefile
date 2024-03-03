USER = knyhle
KEYBOARDS = planck

# keyboard name
NAME_planck = planck/ez

build:
	# init submodule
	git submodule update --init --recursive
	git submodule update --remote

	# add new symlinks
	ln -s $(shell pwd)/keymaps/planck qmk_firmware/keyboards/planck/keymaps/$(USER)

	# run build
	# make BUILD_DIR=$(shell pwd)/build -j1 -C qmk_firmware $(NAME_$@):$(USER)
	cd qmk_firmware && qmk compile -kb planck/ez -km $(USER)

	# cleanup symlinks
	rm -rf qmk_firmware/keyboards/planck/keymaps/$(USER)

flash:
	cd qmk_firmware && qmk flash -kb planck/ez -km $(USER)

clean:
	rm -rf qmk_firmware/keyboards/planck/keymaps/$(USER)


