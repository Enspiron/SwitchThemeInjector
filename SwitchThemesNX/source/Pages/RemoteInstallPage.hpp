#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "../SwitchThemesCommon/SwitchThemesCommon.hpp"
#include "../UI/UI.hpp"
#include "../fs.hpp"
#include "ThemeEntry.hpp"
#ifdef __SWITCH__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#endif

class RemoteInstallPage : public IPage
{
	public:
		RemoteInstallPage();	
		~RemoteInstallPage();
		
		void Render(int X, int Y) override;
		void Update() override;
	private:
		void StartSocketing();
		void StopSocketing();
		void SocketUpdate();
		
		void DialogError(const std::string &msg);
		
		int sock = -1;
	
		//For SocketUpdate:
		int curSock = -1;
		int ThemeSize = 0;
		std::vector<u8> data;
		
		std::string lblInfo;
		std::string lblConfirm;
		ThemeEntry *entry = 0;
		std::string BtnStart;
};