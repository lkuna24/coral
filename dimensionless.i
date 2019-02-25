[Mesh]
  # file = mug.e

    type = GeneratedMesh
    dim = 2
    nx = 10
    ny = 2
    xmin = 0
    xmax = 1
    ymin = 0
    ymax = 1
[]

[Variables]
  [./n]
    order = FIRST
    family = LAGRANGE
    [./InitialCondition]
      type = RandomIC
    [../]
  [../]
  [./p]
    order = FIRST
    family = LAGRANGE
    [./InitialCondition]
      type = RandomIC
    [../]
  [../]
  [./phi]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./Diffusion_e]
    type = ElectronDiff
    variable = phi
    n = n
  [../]
  [./Drift_e]
    type = ElectronDrift
    variable = n
  [../]
  [./Time_e]
    type = TimeDerivative
    variable = n
  [../]

  [./Diffusion_p]
    type = HoleDiff
    variable = phi
    p = p
  [../]
  [./Drift_p]
    type = ElectronDrift
    variable = p
  [../]
  [./Time_p]
    type = TimeDerivative
    variable = p
  [../]

  [./ElectrostaticsCombo]
    type = ElectrostaticsCombo
    variable = phi
    n = n
    p = p
    permittivity = 1
  [../]
[]

[BCs]
  # [./bottom_convected]
  #   type = DirichletBC
  #   variable = phi
  #   boundary = 'bottom'
  #   value = 1
  # [../]
  # [./top_convected]
  #   type = DirichletBC
  #   variable = phi
  #   boundary = 'top'
  #   value = 0
  # [../]
  # [./bottom_diffused]
  #   type = NeumannBC
  #   variable = n
  #   boundary = 'bottom'
  #   value = 0
  # [../]
  # [./top_diffused]
  #   type = NeumannBC
  #   variable = n
  #   boundary = 'top'
  #   value = 0
  # [../]
[]

[Executioner]
  type = Transient
  solve_type = 'PJFNK'
  dt = 0.000001
[]


[Outputs]
  file_base = out
  exodus = true
  [./console]
    type = Console
    perf_log = true
    linear_residuals = false
  [../]
[]
