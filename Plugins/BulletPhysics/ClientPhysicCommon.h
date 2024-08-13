#pragma once

#include <vector>

const int PhysicConfigState_NotLoaded = 0;
const int PhysicConfigState_Loaded = 1;
const int PhysicConfigState_LoadedWithError = 2;

const int PhysicConfigType_None = 0;
const int PhysicConfigType_StaticObject = 1;
const int PhysicConfigType_DynamicObject = 2;
const int PhysicConfigType_RagdollObject = 3;

const int PhysicObjectFlag_Barnacle = 0x1;
const int PhysicObjectFlag_Gargantua = 0x2;
const int PhysicObjectFlag_StaticObject = 0x1000;
const int PhysicObjectFlag_DynamicObject = 0x2000;
const int PhysicObjectFlag_RagdollObject = 0x4000;
const int PhysicObjectFlag_NoConfig = 0x20000;
const int PhysicObjectFlag_FromConfig = 0x40000;
const int PhysicObjectFlag_AnyObject = (PhysicObjectFlag_StaticObject | PhysicObjectFlag_RagdollObject | PhysicObjectFlag_DynamicObject);

const int PhysicRigidBodyFlag_None = 0;
const int PhysicRigidBodyFlag_AlwaysDynamic = 1;
const int PhysicRigidBodyFlag_AlwaysKinematic = 2;
const int PhysicRigidBodyFlag_AlwaysStatic = 4;
const int PhysicRigidBodyFlag_Jiggle = 8;

const int PhysicRigidBodyFlag_AllowedOnStaticObject = (PhysicRigidBodyFlag_AlwaysStatic | PhysicRigidBodyFlag_AlwaysKinematic);
const int PhysicRigidBodyFlag_AllowedOnRagdollObject = (PhysicRigidBodyFlag_AlwaysDynamic | PhysicRigidBodyFlag_AlwaysKinematic | PhysicRigidBodyFlag_Jiggle);

const int PhysicConstraint_None = 0;
const int PhysicConstraint_ConeTwist = 1;
const int PhysicConstraint_Hinge = 2;
const int PhysicConstraint_Point = 3;
const int PhysicConstraint_Slider = 4;
const int PhysicConstraint_Dof6 = 5;
const int PhysicConstraint_Fixed = 6;

const int PhysicConstraintFlag_Barnacle = 0x1;
const int PhysicConstraintFlag_Gargantua = 0x2;
const int PhysicConstraintFlag_NonNative = (PhysicConstraintFlag_Barnacle | PhysicConstraintFlag_Gargantua);

const int PhysicConstraintFactorIdx_ConeTwistSwingSpanLimit1 = 0;
const int PhysicConstraintFactorIdx_ConeTwistSwingSpanLimit2 = 1;
const int PhysicConstraintFactorIdx_ConeTwistTwistSpanLimit = 2;
const int PhysicConstraintFactorIdx_ConeTwistSoftness = 3;
const int PhysicConstraintFactorIdx_ConeTwistBiasFactor = 4;
const int PhysicConstraintFactorIdx_ConeTwistRelaxationFactor = 5;

const int PhysicConstraintFactorIdx_HingeLowLimit = 0;
const int PhysicConstraintFactorIdx_HingeHighLimit = 1;
const int PhysicConstraintFactorIdx_HingeSoftness = 3;
const int PhysicConstraintFactorIdx_HingeBiasFactor = 4;
const int PhysicConstraintFactorIdx_HingeRelaxationFactor = 5;

const int PhysicConstraintFactorIdx_SliderLowerLinearLimit = 0;
const int PhysicConstraintFactorIdx_SliderUpperLinearLimit = 1;
const int PhysicConstraintFactorIdx_SliderLowerAngularLimit = 2;
const int PhysicConstraintFactorIdx_SliderUpperAngularLimit = 3;

const int PhysicConstraintFactorIdx_Dof6LowerLinearLimitX = 0;
const int PhysicConstraintFactorIdx_Dof6LowerLinearLimitY = 1;
const int PhysicConstraintFactorIdx_Dof6LowerLinearLimitZ = 2;
const int PhysicConstraintFactorIdx_Dof6UpperLinearLimitX = 3;
const int PhysicConstraintFactorIdx_Dof6UpperLinearLimitY = 4;
const int PhysicConstraintFactorIdx_Dof6UpperLinearLimitZ = 5;

const int PhysicConstraintFactorIdx_Dof6LowerAngularLimitX = 6;
const int PhysicConstraintFactorIdx_Dof6LowerAngularLimitY = 7;
const int PhysicConstraintFactorIdx_Dof6LowerAngularLimitZ = 8;
const int PhysicConstraintFactorIdx_Dof6UpperAngularLimitX = 9;
const int PhysicConstraintFactorIdx_Dof6UpperAngularLimitY = 10;
const int PhysicConstraintFactorIdx_Dof6UpperAngularLimitZ = 11;

const int PhysicConstraintFactorIdx_LinearERP = 20;
const int PhysicConstraintFactorIdx_LinearCFM = 21;
const int PhysicConstraintFactorIdx_LinearStopERP = 22;
const int PhysicConstraintFactorIdx_LinearStopCFM = 23;
const int PhysicConstraintFactorIdx_AngularERP = 24;
const int PhysicConstraintFactorIdx_AngularCFM = 25;
const int PhysicConstraintFactorIdx_AngularStopERP = 26;
const int PhysicConstraintFactorIdx_AngularStopCFM = 27;
const int PhysicConstraintFactorIdx_RigidBodyLinearDistanceOffset = 28;

const int PhysicShape_None = 0;
const int PhysicShape_Box = 1;
const int PhysicShape_Sphere = 2;
const int PhysicShape_Capsule = 3;
const int PhysicShape_Cylinder = 4;
const int PhysicShape_MultiSphere = 5;
const int PhysicShape_TriangleMesh = 6;

const int PhysicAction_None = 0;

const int PhysicAction_BarnacleDragForce = 1;
const int PhysicActionFactor_BarnacleDragForceMagnitude = 0;
const int PhysicActionFactor_BarnacleDragForceExtraHeight = 1;

const int PhysicAction_BarnacleChewForce = 2;
const int PhysicActionFactor_BarnacleChewForceMagnitude = 0;
const int PhysicActionFactor_BarnacleChewForceInterval = 1;

const int PhysicAction_BarnacleConstraintLimitAdjustment = 3;
const int PhysicActionFactor_BarnacleConstraintLimitAdjustmentExtraHeight = 1;
const int PhysicActionFactor_BarnacleConstraintLimitAdjustmentInterval = 2;

const int PhysicActionFlag_Barnacle = 0x1;
const int PhysicActionFlag_Gargantua = 0x2;
const int PhysicActionFlag_AffectsRigidBody = 0x4;
const int PhysicActionFlag_AffectsConstraint = 0x8;

const int PhysicShapeDirection_X = 0;
const int PhysicShapeDirection_Y = 1;
const int PhysicShapeDirection_Z = 2;

#define BULLET_DEFAULT_DEBUG_DRAW_LEVEL 1
#define BULLET_DEFAULT_SOFTNESS 1.0f
#define BULLET_DEFAULT_BIAS_FACTOR 0.3f
#define BULLET_DEFAULT_RELAXTION_FACTOR 1.0f
#define BULLET_DEFAULT_LINEAR_ERP 0.3f
#define BULLET_DEFAULT_ANGULAR_ERP 0.3f
#define BULLET_DEFAULT_LINEAR_CFM 0.01f
#define BULLET_DEFAULT_ANGULAR_CFM 0.01f
#define BULLET_DEFAULT_LINEAR_STOP_ERP 0.3f
#define BULLET_DEFAULT_ANGULAR_STOP_ERP 0.3f
#define BULLET_DEFAULT_LINEAR_STOP_CFM 0.01f
#define BULLET_DEFAULT_ANGULAR_STOP_CFM 0.01f
#define BULLET_DEFAULT_CCD_THRESHOLD 1e-7
#define BULLET_DEFAULT_LINEAR_FIRCTION 1.0f
#define BULLET_DEFAULT_ANGULAR_FIRCTION 0.2f
#define BULLET_DEFAULT_RESTITUTION 0.0f
#define BULLET_DEFAULT_MASS 1.0f
#define BULLET_DEFAULT_DENSENTY 1.0f
#define BULLET_DEFAULT_LINEAR_SLEEPING_THRESHOLD 5.0f
#define BULLET_DEFAULT_ANGULAR_SLEEPING_THRESHOLD 3.0f
#define BULLET_MAX_TOLERANT_LINEAR_ERROR 30.0f//TODO: use config?

class CPhysicBrushVertex
{
public:
	vec3_t	pos{ 0 };
};

class CPhysicBrushFace
{
public:
	int start_vertex{};
	int num_vertexes{};
};

class CPhysicVertexArray
{
public:
	std::vector<CPhysicBrushVertex> vVertexBuffer;
	std::vector<CPhysicBrushFace> vFaceBuffer;
};

class CPhysicIndexArray
{
public:
	std::vector<int> vIndexBuffer;
};