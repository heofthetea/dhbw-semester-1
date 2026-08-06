> CLI to control [[Kubernetes]]

- everything that can be specified in [[Kubernetes]], can be configured using this CLI
- [[Imperative Programmiersprache|Imperative]] [[Kubernetes Objects|Object]] configuration:
	- Specify what [[Kubernetes]] should do
- [[Declarative Programming Language|declarative]] [[Kubernetes Objects|Object]] configuration:
	- declarative programming with some [[YAML]] shits
	- `kubectl apply -f`
	- [[Kubernetes Control Plane]] compares desired state with actual [[Zustand|state]]
		- figures out on its own what it needs to do and applies those changes
		- similar to [[Terraform]]
- based on [[k8s Deployment]]

> [!hint] [[HTTP]]-based

> [!hint] Installation usually through package repositories

### Statefulness
- is [[Stateful]] in the sense that the **remote** cluster is **remembered**
## List of Commands
### Basic informatin
> [!hint] Basically equivalent to `docker ps`

```bash
kubectl get nodes
```

- other information (in place of "nodes"):
	- `pods` - all deployed [[Kubernetes Pod|Pods]]
	- `deployments` - all configured [[k8s Deployment|deployments]]
	- `replicasets` - all [[Replicaset|Replicasets]]
	- `cert` - certificates 
	- `ing` - [[Ingress]]
	- `all` - for maximum Overkill
	- `crs/csr` -> certificate signing processes (likely a plugin)

> [!hint] Use `kubectl api-resources` to get a list of _everything_ that can be kubectl-gotten.
### The most important one - kubectl apply
```bash
kubectl apply -f $conrig_file
```

### Debugging pods
[[Kubernetes Pod|Pod]]
```bash
kubectl logs $pod_id #logs
kubectl describe $pod_id # some meta information about the pod
kubectl exec -it $pod_id -- $command # execute a command (like a shell)
```

> [!hint] [[kubectl]] automatically detects whether this is a [[#Create Deployment|Create]] or an [[#Edit a deployment|Update]].

### Port-Forwarding
- temporary solution (I guess you should use a [[Reverse Proxy]])
- Can be done at different levels - pod-wise, service-wise, deployment-wise...

```bash
kubectl port-forward deployment/$depl_name $from_port:$to_port
```

> [!hint] Blocks the terminal.
### Mit der Hand am Arm
#### Create Deployment
- [[k8s Deployment]]

```bash
kubectl create deployment $depl_name --image=$image_name
```

- `depl_name`: unique name of the deployment
- `image_name`: the [[Docker Image]] used by the managed [[Kubernetes Pod|Pods]]

> [!hint] Uses defaults for everything else that can be specified in [[k8s Deployment|deployment.yml]]

#### Edit a deployment
```bash
kubectl edit deployment $depl_name
```

> [!hint] Just fucking spawns the [[YAML]] config😂

> [!warning]- Whenever the config changes, a _new_ deployment with unique id gets created.
> The id is probably a hash because it always is
### Delete Deployment
```bash
kubectl delete deployment $depl_name
kubectl delete -f $config_file # everyting is yaml
```

## Plugins
```bash
kubectl ns
```

-> switch namespaces easily


```bash
kubectl ctx
```

-> switch entire contexts (think: Cluster) easily