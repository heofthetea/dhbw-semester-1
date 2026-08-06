> [[Docker Compose]] for [[Helm]]

- bundle multiple charts in a single file
- Handle all Environment Variables in one YAML file


> [!hint] Takes Configs done in `values.yaml` in [[Helm]] as _defaults_  - if not specified in helmfile, the defaults are used

## Configure for [[Create Helm Chart]]

> [!warning] Make sure to use the generic `environments` array approach:
> - In `values.yaml`:
> ```yaml
> environment: []
> ```
> - In `deployment.yaml`, for each container in the `containers` array:
> ```yaml
> env:
>    {{- with .Values.environment }}
>     {{- toYaml . | nindent 12 }}
>    {{- end }}
> ```

-> then, environment variables can be set for the chart under a `environment` tag

> [!hint] Tag name needs to match the generic array -> maybe useful if it's needed to configure something else

> [!hint] For newer versions of helmfile - add `.gotmpl` extension to `helmfile.yaml` to avoid panics

### Environment Variables
- To get environment variables: use `{{ env "env_name" }}` for optional, `{{ requiredEnv "env_name" }}` to fail if env not presenet
## Execution comands
```bash
helmfile init
```
- initialise [[Helmfile]] and install required helm plugins

> [!warning] Mandatory on new installs at least - helm is missing a _truckload_ of plugins (diff, secrets, s3, git)

```bash
helmfile destroy
```
- Remove entire deployment
	- -> useful for force-redeploying BECAUSE THERE'S APPARENTLY NO WAY TO FUCKING FORCE THE THING TO RUN WHAT THE FUKKCKCCCKCKCKCKCKCKC THIS IS A NIGHTMARE FOR DEVELOPMENT

## Helmfile sync vs Helmfile apply
> [!hint] Both update the [[Kubernetes Cluster]]

- **apply**: Interactive, more verbose
	- e.g.: Shows the diff
	- => for manual deployments mainly
- **sync**: Non-Interactive, less info
	- => for [[CICD]]