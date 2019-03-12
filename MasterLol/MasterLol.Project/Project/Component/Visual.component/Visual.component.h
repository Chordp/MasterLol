#pragma once
#include "../IComponent.h"

#include "TurretRange.service.h"
#include "PlayerVisual.service.h"

class VisualComponent : public IComponent
{

public:
	VisualComponent() : IComponent("VISUALS") {
		this->AddGameService<TurretRangeService>();
		this->AddGameService<PlayerVisualService>();
	}

	virtual void RenderMenu() {
		Start(2);

		ImGui::Text("PLAYER :");
		ImGui::Checkbox("AA Range", &Option::Get().show_AA_range);
		ImGui::Checkbox("Q Range", &Option::Get().show_Q_range);
		ImGui::Checkbox("W Range", &Option::Get().show_W_range);
		ImGui::Checkbox("E Range", &Option::Get().show_E_range);
		ImGui::Checkbox("R Range", &Option::Get().show_R_range);


		ImGui::NextColumn();

		ImGui::Text("MISK :");
		ImGui::Checkbox("Turrets AA Range", &Option::Get().show_turrets_AA_range);

		End();
	}
};
