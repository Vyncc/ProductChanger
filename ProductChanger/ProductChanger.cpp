#include "pch.h"
#include "ProductChanger.h"


BAKKESMOD_PLUGIN(ProductChanger, "ProductChanger", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void ProductChanger::onLoad()
{
	_globalCvarManager = cvarManager;

	//Check if scorer is local player, if not it will remove the goal explosion
	gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.ProductAsset_GoalExplosion_TA.GetExplosionFXActorForPRI", [this](ActorWrapper caller, void* params, std::string eventName) {
		UProductAsset_GoalExplosion_TA_execGetExplosionFXActorForPRI_Params* param = reinterpret_cast<UProductAsset_GoalExplosion_TA_execGetExplosionFXActorForPRI_Params*>(params);

		PriWrapper pri = PriWrapper(reinterpret_cast<uintptr_t>(param->PRI));
		if (!pri) return;

		PlayerControllerWrapper playerController = gameWrapper->GetPlayerController();
		if (!playerController) return;

		PriWrapper localPri = playerController.GetPRI();
		if (!localPri) return;

		if (pri.memory_address == localPri.memory_address && !RemoveGoalExplosionForLocalPlayer) return;
		if (pri.memory_address != localPri.memory_address && !RemoveGoalExplosionForOtherPlayers) return;

		ShouldRemoveGoalExplosion = true;
	});

	gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.Ball_TA.SetExplosionFXActor", [this](ActorWrapper caller, void* params, std::string eventName) {
		if (ShouldRemoveGoalExplosion)
		{
			ABall_TA_execSetExplosionFXActor_Params* param = reinterpret_cast<ABall_TA_execSetExplosionFXActor_Params*>(params);
			param->ExplosionFX = NULL;

			ShouldRemoveGoalExplosion = false;
		}
	});

	//Change engine to default for all players unless local player, this function is called when a car is spawned
	gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.EngineAudioREVComponent_TA.InitFromAsset", [this](ActorWrapper caller, void* params, std::string eventName) {
		UEngineAudioREVComponent_TA_execInitFromAsset_Params* param = reinterpret_cast<UEngineAudioREVComponent_TA_execInitFromAsset_Params*>(params);
		uintptr_t* outer = reinterpret_cast<uintptr_t*>(caller.memory_address + OFFSET_OUTER); //outer is the car that owns the caller

		CarWrapper localCar = gameWrapper->GetLocalCar();

		if (localCar.memory_address == *outer && !DefaultEngineForLocalPlayer) return;
		if (localCar.memory_address != *outer && !DefaultEngineForOtherPlayers) return;

		param->EngineAsset = NULL;
	});
}

void ProductChanger::onUnload()
{
}