
#pragma once

#include "Ephemeral/core/App.hpp"

int main(int argc, char** argv) {

	auto ephemeral = EE::CreateApp();
	ephemeral->start();
    delete ephemeral;

}