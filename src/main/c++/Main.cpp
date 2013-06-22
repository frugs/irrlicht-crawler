#include <cstdlib>
#include <iostream>
#include <irrlicht.h>

using namespace std;

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


int main(int argc, char** argv) {
	// start up the engine
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640,480));

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* scenemgr = device->getSceneManager();

	device->setWindowCaption(L"Hello World!");

	// load and show quake2 .md2 model
	IAnimatedMeshSceneNode* node = scenemgr->addAnimatedMeshSceneNode(scenemgr->getMesh("assets/sydney.md2"));

	// if everything worked, add a texture and disable lighting
	if (node) {
		node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture("assets/sydney.bmp"));
	}

	scenemgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

	// draw everything
	while(device->run() && driver)
	{
		driver->beginScene(true, true, video::SColor(255,0,0,255));
		scenemgr->drawAll();
		driver->endScene();
	}

	// delete device
	device->drop();
	return 0;
}