/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "MageActions.h"
#include "MageTriggers.h"
#include "Playerbots.h"

bool ArcaneIntellectOnPartyTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() && !botAI->HasAura("arcane brilliance", GetTarget());
}

bool ArcaneIntellectTrigger::IsActive()
{
    return BuffTrigger::IsActive() && !botAI->HasAura("arcane brilliance", GetTarget());
}

bool MageArmorTrigger::IsActive()
{
    Unit* target = GetTarget();
    return !botAI->HasAura("ice armor", target) && !botAI->HasAura("frost armor", target) && !botAI->HasAura("molten armor", target) && !botAI->HasAura("mage armor", target);
}

bool FingersOfFrostSingleTrigger::IsActive()
{
    // Fingers of Frost "stack" count is always 1.
    // The value is instead stored in the charges.
    Aura *aura = botAI->GetAura(getName(), GetTarget(), false, true, -1);
	return (aura && aura->GetCharges() == 1);
}

bool FrostNovaOnTargetTrigger::IsActive()
{
    Unit* target = GetTarget();
    if (!target || !target->IsAlive() || !target->IsInWorld()) {
        return false;
    }
    bool aura = botAI->HasAura("frostbite", target);
    if (aura)
        LOG_DEBUG("playerbots", ":: FROST NOVA ACTIVE");
	return !botAI->HasAura("frost nova", target);
}

bool FrostbiteOnTargetTrigger::IsActive()
{
    Unit* target = GetTarget();
    if (!target || !target->IsAlive() || !target->IsInWorld()) {
        return false;
    }
    bool aura = botAI->HasAura("frostbite", target);
    if (aura)
        LOG_DEBUG("playerbots", ":: FROSTBITE ACTIVE");
	return botAI->HasAura("frostbite", target);
}
