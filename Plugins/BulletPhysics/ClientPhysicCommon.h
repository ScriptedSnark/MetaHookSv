#pragma once

const int PhysicConfigState_NotLoaded = 0;
const int PhysicConfigState_Loaded = 1;
const int PhysicConfigState_LoadedWithError = 2;

const int PhysicConfigType_None = 0;
const int PhysicConfigType_Ragdoll = 1;
const int PhysicConfigType_Dynamic = 2;

const int PhysicObjectFlag_StaticObject = 1;
const int PhysicObjectFlag_RagdollObject = 2;
const int PhysicObjectFlag_Any = (PhysicObjectFlag_StaticObject | PhysicObjectFlag_RagdollObject);

const int PhysicRigidBodyFlag_AlwaysDynamic = 1;
const int PhysicRigidBodyFlag_AlwaysKinematic = 2;
const int PhysicRigidBodyFlag_AlwaysStatic = 4;
const int PhysicRigidBodyFlag_NoCollisionToOtherEntities = 0x8;
const int PhysicRigidBodyFlag_Jiggle = (PhysicRigidBodyFlag_AlwaysDynamic | PhysicRigidBodyFlag_NoCollisionToOtherEntities);

const int PhysicConstraintFactorIdx_ConeTwistSwingSpanLimit1 = 0;
const int PhysicConstraintFactorIdx_ConeTwistSwingSpanLimit2 = 1;
const int PhysicConstraintFactorIdx_ConeTwistTwistSpanLimit = 2;
const int PhysicConstraintFactorIdx_ConeTwistSoftness = 3;
const int PhysicConstraintFactorIdx_ConeTwistBiasFactor = 4;
const int PhysicConstraintFactorIdx_ConeTwistRelaxationFactor = 5;

const int PhysicConstraintFactorIdx_HingeLowLimit = 0;
const int PhysicConstraintFactorIdx_HingeHighLimit = 1;
const int PhysicConstraintFactorIdx_HingeBiasFactor = 4;
const int PhysicConstraintFactorIdx_HingeRelaxationFactor = 5;

const int PhysicConstraintFactorIdx_LinearERP = 10;
const int PhysicConstraintFactorIdx_LinearCFM = 11;
const int PhysicConstraintFactorIdx_LinearStopERP = 12;
const int PhysicConstraintFactorIdx_LinearStopCFM = 13;
const int PhysicConstraintFactorIdx_AngularERP = 14;
const int PhysicConstraintFactorIdx_AngularCFM = 15;
const int PhysicConstraintFactorIdx_AngularStopERP = 16;
const int PhysicConstraintFactorIdx_AngularStopCFM = 17;

const int PhysicShape_None = 0;
const int PhysicShape_Box = 1;
const int PhysicShape_Sphere = 2;
const int PhysicShape_Capsule = 3;
const int PhysicShape_Cylinder = 4;
const int PhysicShape_MultiSphere = 5;

const int PhysicConstraint_None = 0;
const int PhysicConstraint_Hinge = 1;
const int PhysicConstraint_ConeTwist = 2;
const int PhysicConstraint_Point = 3;

const int PhysicShapeDirection_X = 0;
const int PhysicShapeDirection_Y = 1;
const int PhysicShapeDirection_Z = 2;