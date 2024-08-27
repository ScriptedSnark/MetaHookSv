#include "PhysicUTIL.h"
#include "exportfuncs.h"
#include "Controls.h"

#include <sstream>
#include <format>
#include <algorithm>

const char* VGUI2Token_PhysicObjectType[] = { "#BulletPhysics_None", "#BulletPhysics_StaticObject", "#BulletPhysics_DynamicObject", "#BulletPhysics_RagdollObject" };

const char* UTIL_GetPhysicObjectTypeLocalizationToken(int type)
{
	if (type >= 0 && type < _ARRAYSIZE(VGUI2Token_PhysicObjectType))
	{
		return VGUI2Token_PhysicObjectType[type];
	}

	return "#BulletPhysics_None";
}

const char* VGUI2Token_ConstraintType[] = { "#BulletPhysics_None", "#BulletPhysics_ConeTwistConstraint", "#BulletPhysics_HingeConstraint", "#BulletPhysics_PointConstraint", "#BulletPhysics_SliderConstraint", "#BulletPhysics_Dof6Constraint", "#BulletPhysics_Dof6SpringConstraint", "#BulletPhysics_FixedConstraint" };

const char* UTIL_GetConstraintTypeLocalizationToken(int type)
{
	if (type >= 0 && type < _ARRAYSIZE(VGUI2Token_ConstraintType))
	{
		return VGUI2Token_ConstraintType[type];
	}

	return "#BulletPhysics_None";
}

const char* VGUI2Token_RotOrderType[] = { "#BulletPhysics_PhysicRotOrder_XYZ", "#BulletPhysics_PhysicRotOrder_XZY", "#BulletPhysics_PhysicRotOrder_YXZ", "#BulletPhysics_PhysicRotOrder_YZX", "#BulletPhysics_PhysicRotOrder_ZXY", "#BulletPhysics_PhysicRotOrder_ZYX" };

const char* UTIL_GetRotOrderTypeLocalizationToken(int type)
{
	if (type >= 0 && type < _ARRAYSIZE(VGUI2Token_RotOrderType))
	{
		return VGUI2Token_RotOrderType[type];
	}

	return "#BulletPhysics_PhysicRotOrder_XYZ";
}

const char* VGUI2Token_CollisionShape[] = { "#BulletPhysics_None", "#BulletPhysics_Box", "#BulletPhysics_Sphere", "#BulletPhysics_Capsule", "#BulletPhysics_Cylinder", "#BulletPhysics_MultiSphere", "#BulletPhysics_TriangleMesh", "#BulletPhysics_Compound" };

const char* UTIL_GetCollisionShapeTypeLocalizationToken(int type)
{
	if (type >= 0 && type < _ARRAYSIZE(VGUI2Token_CollisionShape))
	{
		return VGUI2Token_CollisionShape[type];
	}

	return "#BulletPhysics_None";
}

std::wstring UTIL_GetCollisionShapeTypeLocalizedName(int type)
{
	return vgui::localize()->Find(UTIL_GetCollisionShapeTypeLocalizationToken(type));
}

std::wstring UTIL_GetFormattedRigidBodyFlags(int flags)
{
	std::wstringstream ss;

	// Macro to format flag string
#define FORMAT_FLAGS_TO_STRING(name) if (flags & PhysicRigidBodyFlag_##name) {\
        ss << L"(" << vgui::localize()->Find("#BulletPhysics_" #name) << L") ";\
    }

	FORMAT_FLAGS_TO_STRING(AlwaysDynamic);
	FORMAT_FLAGS_TO_STRING(AlwaysKinematic);
	FORMAT_FLAGS_TO_STRING(AlwaysStatic);
	FORMAT_FLAGS_TO_STRING(NoCollisionToWorld);
	FORMAT_FLAGS_TO_STRING(NoCollisionToStaticObject);
	FORMAT_FLAGS_TO_STRING(NoCollisionToDynamicObject);
	FORMAT_FLAGS_TO_STRING(NoCollisionToRagdollObject);

#undef FORMAT_FLAGS_TO_STRING

	return ss.str();
}

std::wstring UTIL_GetFormattedConstraintFlags(int flags)
{
	std::wstringstream ss;

	// Macro to format flag string
#define FORMAT_FLAGS_TO_STRING(name) if (flags & PhysicConstraintFlag_##name) {\
        ss << L"(" << vgui::localize()->Find("#BulletPhysics_" #name) << L") ";\
    }

	FORMAT_FLAGS_TO_STRING(Barnacle);
	FORMAT_FLAGS_TO_STRING(Gargantua);
	FORMAT_FLAGS_TO_STRING(DeactiveOnNormalActivity);
	FORMAT_FLAGS_TO_STRING(DeactiveOnDeathActivity);
	FORMAT_FLAGS_TO_STRING(DeactiveOnBarnacleActivity);
	FORMAT_FLAGS_TO_STRING(DeactiveOnGargantuaActivity);
	FORMAT_FLAGS_TO_STRING(DontResetPoseOnErrorCorrection);

#undef FORMAT_FLAGS_TO_STRING

	return ss.str();
}

std::wstring UTIL_GetFormattedConstraintConfigAttributes(const CClientConstraintConfig *pConstraintConfig)
{
	std::wstringstream ss;

	if (pConstraintConfig->useGlobalJointFromA)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseGlobalJointFromA"));
	}
	else
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseGlobalJointFromB"));
	}
	if (pConstraintConfig->disableCollision)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_DisableCollision"));
	}
	else
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_DontDisableCollision"));
	}
	if (pConstraintConfig->useLookAtOther)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseLookAtOther"));
	}
	if (pConstraintConfig->useGlobalJointOriginFromOther)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseGlobalJointOriginFromOther"));
	}
	if (pConstraintConfig->useRigidBodyDistanceAsLinearLimit)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseRigidBodyDistanceAsLinearLimit"));
	}
	if (pConstraintConfig->useLinearReferenceFrameA)
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseLinearReferenceFrameA"));
	}
	else 
	{
		ss << std::format(L"({0}) ", vgui::localize()->Find("#BulletPhysics_UseLinearReferenceFrameB"));
	}
	return ss.str();
}

std::string UTIL_GetFormattedBoneNameEx(studiohdr_t* studiohdr, int boneindex)
{
	if (!(boneindex >= 0 && boneindex < studiohdr->numbones))
	{
		return "--";
	}

	auto pbone = (mstudiobone_t*)((byte*)studiohdr + studiohdr->boneindex);

	std::string name = pbone[boneindex].name;

	return std::format("#{0} ({1})", boneindex, name);
}

const char* UTIL_GetBoneRawName(studiohdr_t* studiohdr, int boneindex)
{
	if (!(boneindex >= 0 && boneindex < studiohdr->numbones))
	{
		return "--";
	}

	auto pbone = (mstudiobone_t*)((byte*)studiohdr + studiohdr->boneindex);

	return pbone[boneindex].name;
}

std::string UTIL_GetFormattedBoneName(int modelindex, int boneindex)
{
	auto model = EngineGetModelByIndex(modelindex);

	if (!model)
	{
		return "--";
	}

	auto studiohdr = (studiohdr_t*)IEngineStudio.Mod_Extradata(model);

	if (!studiohdr)
	{
		return "--";
	}

	return UTIL_GetFormattedBoneNameEx(studiohdr, boneindex);
}

const char* UTIL_GetPhysicObjectConfigTypeName(int type)
{
	const char* c_names[] = { "None", "StaticObject", "DynamicObject", "RagdollObject" };

	if (type >= 0 && type < _ARRAYSIZE(c_names))
	{
		return c_names[type];
	}

	return "Unknown";
}

const char* UTIL_GetConstraintTypeName(int type)
{
	const char* c_names[] = { "None", "ConeTwist", "Hinge", "Point", "Slider", "Dof6", "Dof6Spring", "Fixed" };

	if (type >= 0 && type < _ARRAYSIZE(c_names))
	{
		return c_names[type];
	}

	return "Unknown";
}

const char* UTIL_GetPhysicActionTypeName(int type)
{
	const char* c_names[] = { "None", "BarnacleDragForce", "BarnacleChewForce", "BarnacleConstraintLimitAdjustment" };

	if (type >= 0 && type < _ARRAYSIZE(c_names))
	{
		return c_names[type];
	}

	return "Unknown";
}

const char* UTIL_GetCollisionShapeTypeName(int type)
{
	const char* c_names[] = { "None", "Box", "Sphere", "Capsule", "Cylinder", "MultiSphere", "TriangleMesh", "Compound" };

	if (type >= 0 && type < _ARRAYSIZE(c_names))
	{
		return c_names[type];
	}

	return "Unknown";
}

int UTIL_GetCollisionTypeFromTypeName(const char* name)
{
	int type = PhysicShape_None;

	if (!strcmp(name, "Box"))
	{
		type = PhysicShape_Box;
	}
	else if (!strcmp(name, "Sphere"))
	{
		type = PhysicShape_Sphere;
	}
	else if (!strcmp(name, "Capsule"))
	{
		type = PhysicShape_Capsule;
	}
	else if (!strcmp(name, "Cylinder"))
	{
		type = PhysicShape_Cylinder;
	}
	else if (!strcmp(name, "MultiSphere"))
	{
		type = PhysicShape_MultiSphere;
	}
	else if (!strcmp(name, "TriangleMesh"))
	{
		type = PhysicShape_TriangleMesh;
	}
	else if (!strcmp(name, "Compound"))
	{
		type = PhysicShape_Compound;
	}

	return type;
}

int UTIL_GetConstraintTypeFromTypeName(const char* name)
{
	int type = PhysicConstraint_None;

	if (!strcmp(name, "ConeTwist"))
	{
		type = PhysicConstraint_ConeTwist;
	}
	else if (!strcmp(name, "Hinge"))
	{
		type = PhysicConstraint_Hinge;
	}
	else if (!strcmp(name, "Point"))
	{
		type = PhysicConstraint_Point;
	}
	else if (!strcmp(name, "Slider"))
	{
		type = PhysicConstraint_Slider;
	}
	else if (!strcmp(name, "Dof6"))
	{
		type = PhysicConstraint_Dof6;
	}
	else if (!strcmp(name, "Dof6Spring"))
	{
		type = PhysicConstraint_Dof6Spring;
	}
	else if (!strcmp(name, "Fixed"))
	{
		type = PhysicConstraint_Fixed;
	}

	return type;
}

int UTIL_GetPhysicActionTypeFromTypeName(const char* name)
{
	int type = PhysicAction_None;

	if (!strcmp(name, "BarnacleDragForce"))
	{
		type = PhysicAction_BarnacleDragForce;
	}
	else if (!strcmp(name, "BarnacleChewForce"))
	{
		type = PhysicAction_BarnacleChewForce;
	}
	else if (!strcmp(name, "BarnacleConstraintLimitAdjustment"))
	{
		type = PhysicAction_BarnacleConstraintLimitAdjustment;
	}

	return type;
}

std::shared_ptr<CClientRigidBodyConfig> UTIL_GetRigidConfigFromConfigId(int configId)
{
	auto pPhysicConfig = ClientPhysicManager()->GetPhysicConfig(configId);

	auto pLockedPhysicConfig = pPhysicConfig.lock();

	if (!pLockedPhysicConfig)
		return nullptr;

	if (pLockedPhysicConfig->configType != PhysicConfigType_RigidBody)
		return nullptr;

	std::shared_ptr<CClientRigidBodyConfig> pRigidBodyConfig = std::static_pointer_cast<CClientRigidBodyConfig>(pLockedPhysicConfig);

	return pRigidBodyConfig;
}

std::shared_ptr<CClientConstraintConfig> UTIL_GetConstraintConfigFromConfigId(int configId)
{
	auto pPhysicConfig = ClientPhysicManager()->GetPhysicConfig(configId);

	auto pLockedPhysicConfig = pPhysicConfig.lock();

	if (!pLockedPhysicConfig)
		return nullptr;

	if (pLockedPhysicConfig->configType != PhysicConfigType_Constraint)
		return nullptr;

	std::shared_ptr<CClientConstraintConfig> pConstraintConfig = std::static_pointer_cast<CClientConstraintConfig>(pLockedPhysicConfig);

	return pConstraintConfig;
}

std::shared_ptr<CClientPhysicObjectConfig> UTIL_GetPhysicObjectConfigFromConfigId(int configId)
{
	auto pPhysicConfig = ClientPhysicManager()->GetPhysicConfig(configId);

	auto pLockedPhysicConfig = pPhysicConfig.lock();

	if (!pLockedPhysicConfig)
		return nullptr;

	if (pLockedPhysicConfig->configType != PhysicConfigType_PhysicObject)
		return nullptr;

	std::shared_ptr<CClientPhysicObjectConfig> pPhysicObjectConfig = std::static_pointer_cast<CClientPhysicObjectConfig>(pLockedPhysicConfig);

	return pPhysicObjectConfig;
}

bool UTIL_RemoveRigidBodyFromPhysicObjectConfig(CClientPhysicObjectConfig * pPhysicObjectConfig, int rigidBodyConfigId)
{
	for (auto itor = pPhysicObjectConfig->RigidBodyConfigs.begin(); itor != pPhysicObjectConfig->RigidBodyConfigs.end(); )
	{
		const auto& p = (*itor);

		if (p->configId == rigidBodyConfigId)
		{
			itor = pPhysicObjectConfig->RigidBodyConfigs.erase(itor);

			pPhysicObjectConfig->configModified = true;

			return true;
		}

		itor++;
	}

	return false;
}

bool UTIL_RemoveConstraintFromPhysicObjectConfig(CClientPhysicObjectConfig* pPhysicObjectConfig, int constraintConfigId)
{
	for (auto itor = pPhysicObjectConfig->ConstraintConfigs.begin(); itor != pPhysicObjectConfig->ConstraintConfigs.end(); )
	{
		const auto& p = (*itor);

		if (p->configId == constraintConfigId)
		{
			itor = pPhysicObjectConfig->ConstraintConfigs.erase(itor);

			pPhysicObjectConfig->configModified = true;

			return true;
		}

		itor++;
	}

	return false;
}

std::shared_ptr<CClientCollisionShapeConfig> UTIL_CloneCollisionShapeConfig(const CClientCollisionShapeConfig* pOldShape)
{
	auto pCloneShape = std::make_shared<CClientCollisionShapeConfig>();
	pCloneShape->configModified = true;
	pCloneShape->configType = pOldShape->configType;
	pCloneShape->type = pOldShape->type;
	pCloneShape->direction = pOldShape->direction;
	VectorCopy(pOldShape->size, pCloneShape->size);
	pCloneShape->is_child = pOldShape->is_child;
	VectorCopy(pOldShape->origin, pCloneShape->origin);
	VectorCopy(pOldShape->angles, pCloneShape->angles);
	//pCloneShape->multispheres = pOldShape->multispheres;
	pCloneShape->resourcePath = pOldShape->resourcePath;

	for (auto& oldChildShape : pOldShape->compoundShapes) {
		auto pClonedShape = UTIL_CloneCollisionShapeConfig(oldChildShape.get());
		pCloneShape->compoundShapes.push_back(pClonedShape);
	}

	return pCloneShape;
}

std::shared_ptr<CClientRigidBodyConfig> UTIL_CloneRigidBodyConfig(const CClientRigidBodyConfig* pOldConfig)
{
	auto pCloneConfig = std::make_shared<CClientRigidBodyConfig>();
	pCloneConfig->configModified = true;
	pCloneConfig->name = pOldConfig->name;
	pCloneConfig->configType = pOldConfig->configType;
	pCloneConfig->flags = pOldConfig->flags;
	pCloneConfig->debugDrawLevel = pOldConfig->debugDrawLevel;
	pCloneConfig->boneindex = pOldConfig->boneindex;
	VectorCopy(pOldConfig->origin, pCloneConfig->origin);
	VectorCopy(pOldConfig->angles, pCloneConfig->angles);
	pCloneConfig->isLegacyConfig = pOldConfig->isLegacyConfig;
	pCloneConfig->pboneindex = pOldConfig->pboneindex;
	pCloneConfig->pboneoffset = pOldConfig->pboneoffset;
	VectorCopy(pOldConfig->forward, pCloneConfig->forward);
	pCloneConfig->mass = pOldConfig->mass;
	pCloneConfig->density = pOldConfig->density;
	pCloneConfig->linearFriction = pOldConfig->linearFriction;
	pCloneConfig->rollingFriction = pOldConfig->rollingFriction;
	pCloneConfig->restitution = pOldConfig->restitution;
	pCloneConfig->ccdRadius = pOldConfig->ccdRadius;
	pCloneConfig->ccdThreshold = pOldConfig->ccdThreshold;
	pCloneConfig->linearSleepingThreshold = pOldConfig->linearSleepingThreshold;
	pCloneConfig->angularSleepingThreshold = pOldConfig->angularSleepingThreshold;

	if (pOldConfig->collisionShape) {
		pCloneConfig->collisionShape = UTIL_CloneCollisionShapeConfig(pOldConfig->collisionShape.get());
	}

	return pCloneConfig;
}

std::shared_ptr<CClientConstraintConfig> UTIL_CloneConstraintConfig(const CClientConstraintConfig* pOldConfig)
{
	auto pNewConfig = std::make_shared<CClientConstraintConfig>();

	// Copy basic types and strings
	pNewConfig->name = pOldConfig->name;
	pNewConfig->type = pOldConfig->type;
	pNewConfig->rigidbodyA = pOldConfig->rigidbodyA;
	pNewConfig->rigidbodyB = pOldConfig->rigidbodyB;
	pNewConfig->disableCollision = pOldConfig->disableCollision;
	pNewConfig->useGlobalJointFromA = pOldConfig->useGlobalJointFromA;
	pNewConfig->useLookAtOther = pOldConfig->useLookAtOther;
	pNewConfig->useGlobalJointOriginFromOther = pOldConfig->useGlobalJointOriginFromOther;
	pNewConfig->useRigidBodyDistanceAsLinearLimit = pOldConfig->useRigidBodyDistanceAsLinearLimit;
	pNewConfig->useLinearReferenceFrameA = pOldConfig->useLinearReferenceFrameA;
	pNewConfig->rotOrder = pOldConfig->rotOrder;
	pNewConfig->flags = pOldConfig->flags;
	pNewConfig->debugDrawLevel = pOldConfig->debugDrawLevel;
	pNewConfig->maxTolerantLinearError = pOldConfig->maxTolerantLinearError;
	pNewConfig->isLegacyConfig = pOldConfig->isLegacyConfig;
	pNewConfig->boneindexA = pOldConfig->boneindexA;
	pNewConfig->boneindexB = pOldConfig->boneindexB;

	// Copy vec3_t using the provided VectorCopy macro
	VectorCopy(pOldConfig->originA, pNewConfig->originA);
	VectorCopy(pOldConfig->anglesA, pNewConfig->anglesA);
	VectorCopy(pOldConfig->originB, pNewConfig->originB);
	VectorCopy(pOldConfig->anglesB, pNewConfig->anglesB);
	VectorCopy(pOldConfig->forward, pNewConfig->forward);
	VectorCopy(pOldConfig->offsetA, pNewConfig->offsetA);
	VectorCopy(pOldConfig->offsetB, pNewConfig->offsetB);

	// Copy array of floats
	std::copy(std::begin(pOldConfig->factors), std::end(pOldConfig->factors), std::begin(pNewConfig->factors));

	return pNewConfig;
}

std::string UTIL_FormatAbsoluteModelName(model_t* mod)
{
	if (mod->type == mod_brush)
	{
		if (mod != r_worldmodel)
		{
			return std::format("{0}/{1}", r_worldmodel->name, mod->name);
		}
		else
		{
			return r_worldmodel->name;
		}
	}

	return mod->name;
}

bool UTIL_IsCollisionShapeConfigModified(const CClientCollisionShapeConfig* pCollisionShapeConfig)
{
	if (pCollisionShapeConfig->configModified)
		return true;

	for (const auto& pSubShapeConfig : pCollisionShapeConfig->compoundShapes)
	{
		if (UTIL_IsCollisionShapeConfigModified(pSubShapeConfig.get()))
		{
			return true;
		}
	}

	return false;
}

bool UTIL_IsPhysicObjectConfigModified(const CClientPhysicObjectConfig* pPhysicObjectConfig)
{
	if (pPhysicObjectConfig->configModified)
		return true;

	for (const auto& pRigidBodyConfig : pPhysicObjectConfig->RigidBodyConfigs)
	{
		if (pRigidBodyConfig->configModified)
			return true;

		const auto &pCollisionShapeConfig = pRigidBodyConfig->collisionShape;

		if (pCollisionShapeConfig)
		{
			if(UTIL_IsCollisionShapeConfigModified(pCollisionShapeConfig.get()))
				return true;
		}
	}

	if (pPhysicObjectConfig->type == PhysicObjectType_DynamicObject)
	{
		const auto pDynamicObjectConfig = (const CClientDynamicObjectConfig*)pPhysicObjectConfig;

		for (const auto& pConstraintConfig : pDynamicObjectConfig->ConstraintConfigs)
		{
			if (pConstraintConfig->configModified)
				return true;
		}
	}
	else if (pPhysicObjectConfig->type == PhysicObjectType_RagdollObject)
	{
		const auto pRagdollObjectConfig = (const CClientRagdollObjectConfig*)pPhysicObjectConfig;

		for (const auto& pConstraintConfig : pRagdollObjectConfig->ConstraintConfigs)
		{
			if (pConstraintConfig->configModified)
				return true;
		}

		for (const auto& pFloaterConfig : pRagdollObjectConfig->FloaterConfigs)
		{
			if (pFloaterConfig->configModified)
				return true;
		}

		for (const auto& pActionConfig : pRagdollObjectConfig->BarnacleControlConfig.ActionConfigs)
		{
			if (pActionConfig->configModified)
				return true;
		}

		for (const auto& pConstraintConfig : pRagdollObjectConfig->BarnacleControlConfig.ConstraintConfigs)
		{
			if (pConstraintConfig->configModified)
				return true;
		}
	}

	return false;
}

void UTIL_SetCollisionShapeConfigUnmodified(CClientCollisionShapeConfig* pCollisionShapeConfig)
{
	pCollisionShapeConfig->configModified = false;

	for (const auto& pSubShapeConfig : pCollisionShapeConfig->compoundShapes)
	{
		UTIL_SetCollisionShapeConfigUnmodified(pSubShapeConfig.get());
	}
}

void UTIL_SetPhysicObjectConfigUnmodified(CClientPhysicObjectConfig* pPhysicObjectConfig)
{
	pPhysicObjectConfig->configModified = false;

	for (const auto& pRigidBodyConfig : pPhysicObjectConfig->RigidBodyConfigs)
	{
		pRigidBodyConfig->configModified = false;

		const auto& pCollisionShapeConfig = pRigidBodyConfig->collisionShape;

		if (pCollisionShapeConfig)
		{
			UTIL_SetCollisionShapeConfigUnmodified(pCollisionShapeConfig.get());
		}
	}

	if (pPhysicObjectConfig->type == PhysicObjectType_DynamicObject)
	{
		const auto pDynamicObjectConfig = (const CClientDynamicObjectConfig*)pPhysicObjectConfig;

		for (const auto& pConstraintConfig : pDynamicObjectConfig->ConstraintConfigs)
		{
			pConstraintConfig->configModified = false;
		}
	}
	else if (pPhysicObjectConfig->type == PhysicObjectType_RagdollObject)
	{
		const auto pRagdollObjectConfig = (const CClientRagdollObjectConfig*)pPhysicObjectConfig;

		for (const auto& pConstraintConfig : pRagdollObjectConfig->ConstraintConfigs)
		{
			pConstraintConfig->configModified = false;
		}

		for (const auto& pFloaterConfig : pRagdollObjectConfig->FloaterConfigs)
		{
			pFloaterConfig->configModified = false;
		}

		for (const auto& pActionConfig : pRagdollObjectConfig->BarnacleControlConfig.ActionConfigs)
		{
			pActionConfig->configModified = false;
		}

		for (const auto& pConstraintConfig : pRagdollObjectConfig->BarnacleControlConfig.ConstraintConfigs)
		{
			pConstraintConfig->configModified = false;
		}
	}
}

IPhysicRigidBody* UTIL_GetPhysicComponentAsRigidBody(int physicComponentId)
{
	auto pPhysicComponent = ClientPhysicManager()->GetPhysicComponent(physicComponentId);

	if (pPhysicComponent && pPhysicComponent->IsRigidBody())
	{
		return (IPhysicRigidBody*)pPhysicComponent;
	}

	return nullptr;
}

IPhysicConstraint* UTIL_GetPhysicComponentAsConstraint(int physicComponentId)
{
	auto pPhysicComponent = ClientPhysicManager()->GetPhysicComponent(physicComponentId);

	if (pPhysicComponent && pPhysicComponent->IsConstraint())
	{
		return (IPhysicConstraint*)pPhysicComponent;
	}

	return nullptr;
}

//RigidBody config order related

int UTIL_GetRigidBodyIndex(const CClientPhysicObjectConfig* pPhysicObjectConfig, int configId)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.begin() && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the previous element
		return currentIndex;
	}

	return -1;
}

int UTIL_GetRigidBodyIndex(const CClientPhysicObjectConfig* pPhysicObjectConfig, const CClientRigidBodyConfig* pRigidBodyConfig)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pRigidBodyConfig](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr.get() == pRigidBodyConfig;
		});

	if (it != configs.begin() && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the previous element
		return currentIndex;
	}

	return -1;
}

bool UTIL_ShiftUpRigidBodyIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, int configId)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.begin() && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the previous element
		std::size_t prevIndex = currentIndex - 1;

		// Swap the current element with the previous one
		std::iter_swap(configs.begin() + currentIndex, configs.begin() + prevIndex);

		return true;
	}

	return false;
}

bool UTIL_ShiftUpRigidBodyIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, CClientRigidBodyConfig* pRigidBodyConfig)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pRigidBodyConfig](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr.get() == pRigidBodyConfig;
		});

	if (it != configs.begin() && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the previous element
		std::size_t prevIndex = currentIndex - 1;

		// Swap the current element with the previous one
		std::iter_swap(configs.begin() + currentIndex, configs.begin() + prevIndex);

		return true;
	}

	return false;
}

bool UTIL_ShiftDownRigidBodyIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, int configId)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.end() - 1 && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the next element
		std::size_t nextIndex = currentIndex + 1;

		// Swap the current element with the next one
		std::iter_swap(configs.begin() + currentIndex, configs.begin() + nextIndex);

		return true;
	}

	return false;
}

bool UTIL_ShiftDownRigidBodyIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, CClientRigidBodyConfig* pRigidBodyConfig)
{
	auto& configs = pPhysicObjectConfig->RigidBodyConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pRigidBodyConfig](const std::shared_ptr<CClientRigidBodyConfig>& ptr) {
		return ptr.get() == pRigidBodyConfig;
		});

	if (it != configs.end() - 1 && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the next element
		std::size_t nextIndex = currentIndex + 1;

		// Swap the current element with the next one
		std::iter_swap(configs.begin() + currentIndex, configs.begin() + nextIndex);

		return true;
	}

	return false;
}

//Constraint config order related

int UTIL_GetConstraintIndex(const CClientPhysicObjectConfig* pPhysicObjectConfig, int configId) {
	const auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.end()) {
		return std::distance(configs.begin(), it);
	}

	return -1; // Return -1 if not found
}

int UTIL_GetConstraintIndex(const CClientPhysicObjectConfig* pPhysicObjectConfig, const CClientConstraintConfig* pConstraintConfig)
{
	auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pConstraintConfig](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr.get() == pConstraintConfig;
		});

	if (it != configs.begin() && it != configs.end()) {
		// Find the index of the current element
		std::size_t currentIndex = std::distance(configs.begin(), it);
		// Calculate the index of the previous element
		return currentIndex;
	}

	return -1;
}

bool UTIL_ShiftUpConstraintIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, int configId) {
	auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.begin() && it != configs.end()) {
		auto currentIndex = std::distance(configs.begin(), it);
		auto prevIndex = currentIndex - 1;

		std::iter_swap(configs.begin() + currentIndex, configs.begin() + prevIndex);
		return true;
	}

	return false;
}

bool UTIL_ShiftDownConstraintIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, int configId) {
	auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [configId](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr->configId == configId;
		});

	if (it != configs.end() - 1 && it != configs.end()) {
		auto currentIndex = std::distance(configs.begin(), it);
		auto nextIndex = currentIndex + 1;

		std::iter_swap(configs.begin() + currentIndex, configs.begin() + nextIndex);
		return true;
	}

	return false;
}

bool UTIL_ShiftUpConstraintIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, CClientConstraintConfig* pConstraintConfig) {
	auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pConstraintConfig](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr.get() == pConstraintConfig;
		});

	if (it != configs.begin() && it != configs.end()) {
		auto currentIndex = std::distance(configs.begin(), it);
		auto prevIndex = currentIndex - 1;

		std::iter_swap(configs.begin() + currentIndex, configs.begin() + prevIndex);
		return true;
	}

	return false;
}

bool UTIL_ShiftDownConstraintIndex(CClientPhysicObjectConfig* pPhysicObjectConfig, CClientConstraintConfig* pConstraintConfig) {
	auto& configs = pPhysicObjectConfig->ConstraintConfigs;

	auto it = std::find_if(configs.begin(), configs.end(), [pConstraintConfig](const std::shared_ptr<CClientConstraintConfig>& ptr) {
		return ptr.get() == pConstraintConfig;
		});

	if (it != configs.end() - 1 && it != configs.end()) {
		auto currentIndex = std::distance(configs.begin(), it);
		auto nextIndex = currentIndex + 1;

		std::iter_swap(configs.begin() + currentIndex, configs.begin() + nextIndex);
		return true;
	}

	return false;
}