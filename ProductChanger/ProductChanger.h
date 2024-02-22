#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

#define OFFSET_OUTER 0x40

// Function TAGame.ProductAsset_GoalExplosion_TA.GetExplosionFXActorForPRI
// [0x00020003] 
struct UProductAsset_GoalExplosion_TA_execGetExplosionFXActorForPRI_Params
{
	void* PRI;                                              		// 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	void* ReturnValue;                                      		// 0x0008 (0x0008) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// int32_t                                            SlotIndex;                                        		// 0x0010 (0x0004) [0x0000000000000000]               
};

// Function TAGame.Ball_TA.SetExplosionFXActor
// [0x04820103] 
struct ABall_TA_execSetExplosionFXActor_Params
{
	void* InExplosion;                                      		// 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	void* ExplosionGoal;                                    		// 0x0008 (0x0008) [0x0000000004000080] (CPF_Parm | CPF_EditInline)
	void* ExplosionFX;                                      		// 0x0010 (0x0008) [0x0000000000000080] (CPF_Parm)    
	void* GoalOrientation;                                  		// 0x0018 (0x0008) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                            OtherTeam;                                        		// 0x0020 (0x0004) [0x0000000000000000]               
	// struct FLinearColor                                ExplosionColor;                                   		// 0x0024 (0x0010) [0x0000000000000000]               
	// class AFXActor_TA*                                 FX;                                               		// 0x0038 (0x0008) [0x0000000000000000]               
};

// Function TAGame.EngineAudioREVComponent_TA.InitFromAsset
// [0x400080002] 
struct UEngineAudioREVComponent_TA_execInitFromAsset_Params
{
	class UProductAsset_EngineAudio_TA* EngineAsset;                                      		// 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	// class UEngineAudioProfileREV_TA*                   NoneCoalescing_0x1;                               		// 0x0008 (0x0008) [0x0000000000000000]               
	// class UAkRevPhysicsSimulation*                     NoneCoalescing_0x2;                               		// 0x0010 (0x0008) [0x0000000000000000]               
	// class UEngineAudioRevSimLimiter_TA*                NoneCoalescing_0x3;                               		// 0x0018 (0x0008) [0x0000000004000000] (CPF_EditInline)
};

class ProductChanger: public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow/*, public BakkesMod::Plugin::PluginWindow*/
{
	bool RemoveGoalExplosionForLocalPlayer = false;
	bool DefaultEngineForLocalPlayer = false;
	bool RemoveGoalExplosionForOtherPlayers = true;
	bool DefaultEngineForOtherPlayers = true;

	bool ShouldRemoveGoalExplosion = false;

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	// Inherited via PluginSettingsWindow
	void RenderSettings() override;
	std::string GetPluginName() override;
	void SetImGuiContext(uintptr_t ctx) override;

	// Inherited via PluginWindow
	/*

	bool isWindowOpen_ = false;
	bool isMinimized_ = false;
	std::string menuTitle_ = "ProductChanger";

	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;
	
	*/
};

