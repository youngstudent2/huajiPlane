#include "LoadState.h"

 void LoadState::init() {

}

 void LoadState::render() {
	std::cerr << "LoadState here";
}

 void LoadState::update() {

}

 void LoadState::keyInput(int key) {
	std::cerr << key << endl;
	if (key == InputHandle::KEY_ENTER)setCurrentState(PlayState());
}
